class Solution {
public:
    int f(int i, int n, vector<int> &arr, vector<int> &dp)
    {
        if(i==n-2 or i == n-1)  return 0;

        if(dp[i+1]!=INT_MAX)    return dp[i+1];

        dp[i+1] = min( (arr[i+1] + f(i+1, n, arr, dp)) ,  (arr[i+2] + f(i+2, n, arr, dp)) );

        return dp[i+1];
    }

    int minCostClimbingStairs(vector<int> &arr) {
        vector<int> dp(arr.size()+1, INT_MAX);
        return f(-1, arr.size(), arr, dp);
    }
};