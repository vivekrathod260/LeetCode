class Solution {
public:
    vector<string> buildArray(vector<int> &t, int N) {
        vector<string> ans;
        int n = t.size();
        int top = 0;    //think   for oth iteration
        
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<(t[i]-top-1); j++)
            {
                ans.push_back("Push");
                ans.push_back("Pop");
            }

            ans.push_back("Push");
            top = t[i];
        }

        return ans;
    }
};