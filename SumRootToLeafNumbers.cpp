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
    int sumNumbers(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int result = 0;
        calc_sum(root, 0, result);
        return result;
    }
private:
    void calc_sum(TreeNode* root, int cur_sum, int& result) {
        cur_sum = cur_sum * 10 + root->val;
        if (!root->left && !root->right) {
            result += cur_sum;
            return;
        }
        if (root->left) {
            calc_sum(root->left, cur_sum, result);
        }
        if (root->right) {
            calc_sum(root->right, cur_sum, result);
        }
    }
};
