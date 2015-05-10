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
        return check_balance(root) >= 0;
    }
private:
    int abs(int a) {
        return a > 0 ? a : -a;
    }
    int check_balance(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int left_depth = check_balance(root->left);
        if (left_depth < 0) {
            return -1;
        }
        int right_depth = check_balance(root->right);
        if (right_depth < 0) {
            return -1;
        }
        if (abs(left_depth - right_depth) > 1) {
            return -1;
        }
        return 1 + max(left_depth, right_depth);
    }
};
