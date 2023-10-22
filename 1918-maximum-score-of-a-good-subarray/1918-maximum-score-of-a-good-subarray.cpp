class Solution {
public:
    int maximumScore(vector<int> &v, int k) {
        int n = v.size();
        int i = k, j = k;
        int ans = v[k];
        int curmin = v[k];

        while(i>=0 || j<n)
        {
            ans = max(ans, curmin*(j-i+1));

            if(i!= 0 and (j == n-1 || v[i-1]>v[j+1]))
            {
                i--;
                curmin = min(curmin, v[i]);
            }
            else if(j!=n-1 and (i==0 || v[j+1]>v[i-1]))
            {
                j++;
                curmin = min(curmin, v[j]);
            }
            else
            {
                if(i==0 and j==n-1) break;

                i--;
                j--;
                curmin = min(curmin, v[i]);
            }
        }

        return ans;
    }
};