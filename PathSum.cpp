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
    bool hasPathSum(TreeNode *root, int sum) {
        if(!root)
            return false;
        sum -= root->val;
        if(root->left == NULL && root->right == NULL && sum == 0)
            return true;
        if(root->left) {
            bool l = hasPathSum(root->left, sum);
            if(l)
                return true;
        }
        if(root->right) {
            bool r = hasPathSum(root->right, sum);
            if(r)
                return true;
        }
        return false;
    }
};
