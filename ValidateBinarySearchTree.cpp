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
    bool isValidBST(TreeNode* root) {
        return check_valid(root, (long long)INT_MIN - 1, (long long)INT_MAX + 1);
    }
private:
    bool check_valid(TreeNode* root, long long left_bound, long long right_bound) {
        if (!root) {
            return true;
        } else {
            if (root->val <= left_bound || root->val >= right_bound) {
                return false;
            }
            return check_valid(root->left, left_bound, root->val)
                    && check_valid(root->right, root->val, right_bound);
        }
    }
};