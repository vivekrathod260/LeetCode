class Solution {
public:
    vector<int> sortArrayByParity(vector<int> &nums) {
        int i = 0, j = nums.size()-1;

        while(i<=j)
        {
            if(nums[i]%2==0)
            {
                i++;
                continue;
            }

            if(nums[j]%2!=0)
            {
                j--;
                continue;
            }

            swap(nums[i], nums[j]);
        }

        // while (i < j) {
        //     while (i < j && nums[i] % 2 == 0)
        //         i++;
        //     while (i < j && nums[j] % 2 == 1)
        //         j--;
            
        //     std::swap(nums[i], nums[j]);
        // }

        return nums;
    }
};