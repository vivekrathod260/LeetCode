class Solution {
public:
    int LIS(int ind, int prev, vector<int> &v, int n, vector<vector<int>> &dp)
    {
        int len = 0;
        if(ind == n)    return 0;
        
        if(dp[ind][prev +1] != -1)  return dp[ind][prev +1];

        len = 0 + LIS(ind+1, prev, v, n, dp);
        if(prev == -1 || v[ind] > v[prev])
        {
            len = max(len, 1 + LIS(ind+1, ind, v, n, dp));
        }

        dp[ind][prev +1] = len;
        return len;
    }
    
    int lengthOfLIS(vector<int> &v) {
        int n = v.size();
        vector<vector<int>> dp(n, vector<int>(n+1,-1));
        return LIS(0, -1, v, n, dp);
    }
};