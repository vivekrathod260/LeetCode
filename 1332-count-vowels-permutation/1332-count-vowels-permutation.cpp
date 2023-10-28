class Solution {
    int n;
    int mod;
public:
    int solve(int i, int prev, vector<vector<int>> &dp)
    {
        if(i == n) return 1;

        if(i == 0)
        {
            int n1 = solve(i+1, 1, dp); //select a
            int n2 = solve(i+1, 2, dp); //select e
            int n3 = solve(i+1, 3, dp); //select i
            int n4 = solve(i+1, 4, dp); //select o
            int n5 = solve(i+1, 5, dp); //select u


            // dp[i][prev] = n1+n2+n3+n4+n5;
            dp[i][prev] = (  ((((n1%mod)+(n2%mod))%mod + ((n3%mod)+(n4%mod))%mod)%mod +n5)%mod);
            return dp[i][prev]%mod;
        }

        if(dp[i][prev] != -1)   return dp[i][prev]%mod;

        if(prev == 1)
        {
            int n2 = solve(i+1, 2, dp); //select e

            dp[i][prev] = n2%mod;
        }
        else if(prev == 2)
        {
            int n1 = solve(i+1, 1, dp); //select a
            int n3 = solve(i+1, 3, dp); //select i

            // dp[i][prev] = n1+n3;
            dp[i][prev] = ((n1%mod)+(n3%mod))%mod;
        }
        else if(prev == 3)
        {
            int n1 = solve(i+1, 1, dp); //select a
            int n2 = solve(i+1, 2, dp); //select e
            int n4 = solve(i+1, 4, dp); //select o
            int n5 = solve(i+1, 5, dp); //select u
            
            
            // dp[i][prev] = n1+n2+n4+n5;
            dp[i][prev] = ((((n1%mod)+(n2%mod))%mod) + (((n4%mod)+(n5%mod))%mod))%mod;
        }
        else if(prev == 4)
        {
            int n3 = solve(i+1, 3, dp); //select i
            int n5 = solve(i+1, 5, dp); //select u
            
            dp[i][prev] = ((n3%mod)+(n5%mod))%mod;
        }
        else if(prev == 5)
        {
            int n1 = solve(i+1, 1, dp); //select a
            
            dp[i][prev] = n1%mod;
        }

        return dp[i][prev]%mod;
    }

    int countVowelPermutation(int N) {
        n = N;
        mod = 1e9 + 7;
        vector<vector<int>> dp(N, vector<int>(6,-1));
        return solve(0, 0, dp)%mod;
    }
};