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
    int maxPathSum(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int max_sum = root->val;
        do_calc_max_sum(root, max_sum);
        return max_sum;
    }
private:
    int do_calc_max_sum(TreeNode* root, int& max_sum) {
        if (!root) {
            return 0;
        }
        int left_sum = do_calc_max_sum(root->left, max_sum);
        int right_sum = do_calc_max_sum(root->right, max_sum);
        int branch_max_sum = max(left_sum, right_sum);
        max_sum = max(max_sum, max(root->val, max(branch_max_sum + root->val, left_sum + right_sum + root->val)));
        return max(branch_max_sum + root->val, root->val);
    }
};