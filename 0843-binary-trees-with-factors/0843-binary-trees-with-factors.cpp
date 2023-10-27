class Solution {
public:
    int bs(int s, int e, int tar, vector<int> &v)
    {
        int mid = (s+e)/2;

        while(s<=e)
        {
            mid = (s+e)/2;

            if(tar == v[mid])
            {
                return mid;
            }
            else if(tar < v[mid])
            {
                e = mid-1;
            }
            else if(tar > v[mid])
            {
                s = mid+1;
            }
        }

        return -1;
    }

    int numFactoredBinaryTrees(vector<int> &v) {
        int n = v.size();
        int MOD = 1e9 + 7;
        long long int ans = 0;
        
        sort(v.begin(), v.end());

        vector<long long int> dp(n, 0);

        dp[0] = 1;
        ans = ans + dp[0];



        for(int i = 1; i<n; i++)
        {
            dp[i] = 1;

            for(int j = i-1; j>=0; j--)
            {
                if(v[i]%v[j] == 0)
                {
                    int f1 = v[j];
                    int f2 = v[i]/v[j];
                    int f2ind = bs(0, j, f2, v);

                    if(f2ind != -1)
                    {
                        if(f1 == f2)
                        {
                            // dp[i] = dp[i] + dp[j]*dp[f2ind];
                           dp[i] = ( (dp[i]%MOD) + ((dp[j]%MOD)*(dp[f2ind]%MOD))%MOD )%MOD;
                        }
                        else
                        {
                            // dp[i] = dp[i] + dp[j]*dp[f2ind]*2;
                            dp[i] = ((dp[i]%MOD) + (  (( (dp[j]%MOD)*(dp[f2ind]%MOD) )%MOD  )*2)%MOD )%MOD;
                        }
                    }
                }

            }

            ans = (ans%MOD + dp[i]%MOD)%MOD;
        }

        return (int)(ans%MOD);
    }
};