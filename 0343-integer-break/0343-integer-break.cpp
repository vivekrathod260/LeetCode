class Solution {
public:
    int f(int n, vector<int> &dp)
    {
        if(dp[n]!=-1)   return dp[n];

        int ans = 0;

        if(n<=3)    
        {
            dp[n] = n-1;
            return dp[n];
        }

        for(int i=1; i<n; i++)
        {
            ans = max(ans, i*max(n-i, f(n-i, dp)));
        }

        dp[n] = ans;
        return dp[n];
    }

    int integerBreak(int n) {
        vector<int> dp(60,-1);
        return f(n, dp);
    }
};