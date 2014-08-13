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
    bool isBalanced(TreeNode *root) {
        return balanced_tree_height(root) >= 0;
    }
private:
    int balanced_tree_height(TreeNode *root)
    {
        if(!root)
            return 0;
        int left_height = balanced_tree_height(root->left);
        if(left_height < 0)
            return -1;
        int right_height = balanced_tree_height(root->right);
        if(right_height < 0 || abs(left_height - right_height) > 1)
            return -1;
        return max(left_height, right_height) + 1;
    }
};
