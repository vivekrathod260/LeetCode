class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        // dp[i] is the max subset sum which ENDING AT i
        vector<int> dp(nums.size(), 0);
        // window contains dp[i - k:i] and a additional 0.
        multiset<int> window = {0};
        
        for(int i = 0; i < nums.size(); i++) {
            // dp[i] = nums[i] + max(0, dp[i - k: i])
            dp[i] = nums[i] + *window.rbegin();
            // update window.
            window.insert(dp[i]);
            if(i >= k) window.erase(window.find(dp[i - k]));
        }
        
        // return max(dp)
        return *max_element(dp.begin(), dp.end());
    }
};