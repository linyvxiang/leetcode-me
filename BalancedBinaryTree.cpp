/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return check_balance(root);
    }
private:
    int tree_depth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        return 1 + max(tree_depth(root->left), tree_depth(root->right));
    }
    bool check_balance(TreeNode* root) {
        if (!root) {
            return true;
        }
        int left_depth = tree_depth(root->left);
        int right_depth = tree_depth(root->right);
        if (left_depth - right_depth < -1
                || left_depth - right_depth > 1) {
            return false;
        }
        return check_balance(root->left)
                && check_balance(root->right);
    }

};