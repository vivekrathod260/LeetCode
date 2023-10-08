class Solution {
public:
    int N1, N2;

    int solve(int i, int j, vector<int> &v1, vector<int> &v2, vector<vector<int>> &dp)
    {
        if(i==N1 or j==N2)  return 0;

        if(dp[i][j]!=INT_MIN) return dp[i][j];

        long ans1 = (v1[i]*v2[j]) + solve(i+1, j+1, v1, v2, dp);
        long ans2 = 0 + solve(i, j+1, v1, v2, dp);
        long ans3 = 0 + solve(i+1, j, v1, v2, dp);
        long ans4 = 0 + solve(i+1, j+1, v1, v2, dp);

        dp[i][j] = max(max(ans1, ans2), max(ans3, ans4));
        return dp[i][j];
    }

    int maxDotProduct(vector<int> &v1, vector<int> &v2) {
        N1 = v1.size();
        N2 = v2.size();
        vector<vector<int>> dp(N1, vector<int>(N2,INT_MIN));

        int ans = solve(0, 0, v1, v2, dp);

        if(ans == 0)    // for tackling case like case 3 one arr completely +ve and one completely -ve
        {
            vector<int> temp(4,0);
            temp[0] = INT_MAX;
            temp[1] = INT_MIN;
            temp[2] = INT_MAX;
            temp[3] = INT_MIN;
            for(int i = 0; i<N1; i++)
            {
                temp[0] = min(temp[0], v1[i]);
                temp[1] = max(temp[1], v1[i]);
            }
            for(int i = 0; i<N2; i++)
            {
                temp[2] = min(temp[2], v2[i]);
                temp[3] = max(temp[3], v2[i]);
            }
            sort(temp.begin(), temp.end());
            return temp[1]*temp[2];
        }

        return ans;
    }
};