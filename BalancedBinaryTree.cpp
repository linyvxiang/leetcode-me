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
    int calc_height(TreeNode *root)
    {
        if(!root)
            return 0;
        return max(calc_height(root->left), calc_height(root->right)) + 1;
    }
    bool isBalanced(TreeNode *root) {
        if(!root)
            return true;
        if(isBalanced(root->left) && isBalanced(root->right)) {
            int l_height = calc_height(root->left);
            int r_height = calc_height(root->right);
            int diff = (l_height > r_height) ? (l_height - r_height) : (r_height - l_height);
            if(diff <= 1)
                return true;
        }
        return false;
    }
};
