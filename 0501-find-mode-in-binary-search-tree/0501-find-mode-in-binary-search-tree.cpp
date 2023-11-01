/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        map<int,int> mp;

        stack<pair<TreeNode*,int>> st;
        st.push(make_pair(root,1));

        pair<TreeNode*,int> p;

        while(st.size()!=0) // dfs
        {
            p = st.top();
            
            if(p.second == 1)   mp[p.first->val]++;

            if(p.second == 1)
            {
                if(p.first->left != NULL)
                {
                    p.second++;
                    st.pop(); st.push(p); //update top

                    st.push(make_pair(p.first->left, 1));
                    continue;
                }
                else p.second++;
            }
            
            if(p.second == 2)
            {
                if(p.first->right != NULL)
                {
                    p.second++;
                    st.pop(); st.push(p); //update top

                    st.push(make_pair(p.first->right, 1));
                    continue;
                }
                else p.second++;
            }

            st.pop();
        }

        int mode = INT_MIN;
        for(pair<int,int> p: mp) { mode = max(mode, p.second); }
        for(pair<int,int> p: mp) { if(p.second == mode) ans.push_back(p.first); }

        return ans;
    }
};