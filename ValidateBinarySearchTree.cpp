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
        return check_valid(root, (long long)INT_MIN - 1,
                (long long)INT_MAX + 1);
    }
private:
    bool check_valid(TreeNode* root, long long min_val,
                    long long max_val) {
        if (!root) {
            return true;
        }
        if (root->val <= min_val || root->val >= max_val) {
            return false;
        }
        return check_valid(root->left, min_val, root->val) &&
                check_valid(root->right, root->val, max_val);
    }
};
