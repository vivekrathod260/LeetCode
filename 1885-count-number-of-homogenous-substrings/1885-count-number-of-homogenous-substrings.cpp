class Solution {
    long long MOD;
public:
    int f(int n)
    {
        // int ans = 0; //this code is for understanding whats formula calculating
        // for(int sz = 1; sz<=n; i++)
        // {
        //     ans = ans + (n-sz+1);
        // }
        // return ans;

        // return ( (n*n) + n - ( (n*(n+1))/2) );
        return (  (((((n%MOD)*(n%MOD))%MOD) + (n%MOD))%MOD)  - ( ( (n%MOD)*((n+1)%MOD) )%MOD  /2  )%MOD          )%MOD;
    }

    int countHomogenous(string s) {
        int n = s.size();
        int cnt = 0, ans = 0;
        char temp = s[0];
        MOD = 1e9+7;

        for(int i = 0; i<n; i++)
        {
            if(s[i]==temp)
            {
                cnt++;
            }
            else 
            {
                // ans = ans + f(cnt);
                ans = ((ans%MOD) + (f(cnt)%MOD))%MOD;
                temp = s[i];
                cnt = 1;
            }
        }

        // ans = ans + f(cnt);
        ans = ((ans%MOD) + (f(cnt)%MOD))%MOD;

        return ans;
    }
};