class Solution {
public:
    int minOperations(vector<int> &nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 1, j = 1;
        for(i = 1; i<n; i++)
        {
            if(nums[i]!=nums[j-1])
            {
                nums[j] = nums[i];
                j++;
            }
        }
        int N = j;

        int maxEleInOneSlideWindow = 0;

        i = 0;
        j = 0;

        while(i<N)
        {
            // j = i;  by avoiding this time complexity can be greatly improved

            while(j < N and nums[j] <= nums[i]+ n-1) j++;

            if(j-i > maxEleInOneSlideWindow)    maxEleInOneSlideWindow = j-i;

            i++;
        }

        return(n-maxEleInOneSlideWindow);
    }
};