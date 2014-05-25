/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode *root) {
        if(!root)
            return 0;
        if(!root->left && !root->right)
            return 1;
        int l_height = INT_MAX, r_height = INT_MAX;
        if(root->left)
            l_height = 1 + minDepth(root->left);
        if(root->right)
            r_height = 1 + minDepth(root->right);
        return min(l_height, r_height);
    }
};
