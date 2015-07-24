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
        return check_balanced(root) >= 0;
    }
private:
    int check_balanced(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int left = check_balanced(root->left);
        int right = check_balanced(root->right);
        if (left < 0 || right < 0) {
            return -1;
        }
        if (abs(left - right) <= 1) {
            return max(left, right) + 1;
        } else {
            return -1;
        }
    }
};
