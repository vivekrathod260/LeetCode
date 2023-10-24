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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;

        int sz = 1;
        int cnt = 0;
        int maxx = INT_MIN;
        TreeNode *tmp = NULL;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            maxx = INT_MIN;
            cnt = 0;

            for(int i = 0; i<sz; i++)
            {
                tmp = q.front(); q.pop();

                if(tmp != NULL)
                { 
                    cnt++;
                    maxx = max(maxx, tmp->val);
                    q.push(tmp->left);
                    q.push(tmp->right);
                }
            }
            sz = cnt*2;

            if(cnt != 0)    ans.push_back(maxx);
        }

        return ans;
    }
};