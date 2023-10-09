class Solution {
public:
    vector<int> searchRange(vector<int> &v, int target) {
        int n = v.size();
        vector<int> ans(2);
        int i;
        int s = 0;
        int e = v.size()-1;
        int mid = (s+e)/2;

        while(s<=e)
        {
            if(v[mid] == target)
            {
                i = mid;
                while(i>-1 and v[i] == target) i--;
                ans[0] = i+1;

                i = mid+1;
                while(i<n and v[i] == target) i++;
                ans[1] = i-1;

                return ans;
            }
            else if(target<v[mid])
            {
                e = mid-1;
                mid = (s+e)/2;
            }
            else
            {
                s = mid+1;
                mid = (s+e)/2;
            }
        }

        ans[0] = -1;
        ans[1] = -1;
        return ans;
    }
};