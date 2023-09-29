class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0;
        int n = nums.size();

        if(n==1) return true;

        for(int i = 1; i<n; i++) {
            if(nums[i-1]<=nums[i]) cnt1++;
            if(nums[i]<=nums[i-1]) cnt2++;
        }

        if(cnt1==n-1 || cnt2==n-1) return true;

        return false;
    }
};