class Solution {
public:
    int f(int i, int rem, int n, vector<int> &c, vector<int> &t, vector<vector<int>> &dp)
    {
        if(rem <= 0) return 0;
        if(i==n) return 1e9;

        if(dp[i][rem] != -1)    return dp[i][rem];

        int c1 = c[i] + f(i+1, rem-1-t[i], n, c, t, dp);

        int c2 = 0 + f(i+1, rem, n, c, t, dp);

        return dp[i][rem] = min(c1, c2);
        return dp[i][rem];
    }

    int paintWalls(vector<int> &c, vector<int> &t) {
        int n = c.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return f(0, n, n, c, t, dp);
    }
};