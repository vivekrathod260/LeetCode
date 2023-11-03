class Solution {
public:
    vector<string> buildArray(vector<int> &t, int N) {
        vector<string> ans;
        int n = t.size();
        int top = INT_MIN;
        
        for(int i = 0; i<n; i++)
        {
            if(i==0)
            {
                for(int j = 0; j<(t[i]-1); j++)     // think test case [5,6,7]
                {
                    ans.push_back("Push");
                    ans.push_back("Pop");
                }

                ans.push_back("Push");
                top = t[i];
                continue;
            }

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