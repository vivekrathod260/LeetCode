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
    int ans;
public:
    pair<int,int> dfs(TreeNode *root)
    {
        if(root==NULL)  return make_pair(0,0);
        pair<int,int> p1,p2,p3;

        p1 = dfs(root->left);
        p2 = dfs(root->right);

        p3.first = p1.first + p2.first + root->val;
        p3.second = p1.second + p2.second + 1;

        if((p3.first/p3.second) == root->val)    ans++;

        return p3;
    }

    int averageOfSubtree(TreeNode* root) {
        ans = 0;
        dfs(root);

        return ans;
    }
};