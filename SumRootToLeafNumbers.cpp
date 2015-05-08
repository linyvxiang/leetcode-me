class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return do_calc_sum(root, 0);
    }
private:
    int do_calc_sum(TreeNode* root, int cur_sum) {
        if (!root) {
            return 0;
        }
        cur_sum = cur_sum * 10 + root->val;
        if (!root->left && !root->right) {
            return cur_sum;
        }
        return do_calc_sum(root->left, cur_sum) +
                do_calc_sum(root->right, cur_sum);
    }
};
