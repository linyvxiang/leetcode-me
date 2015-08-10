class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int cur_max_sum = INT_MIN;
        check_max_sum(root, cur_max_sum);
        return cur_max_sum;
    }
private:
    int check_max_sum(TreeNode* root, int& cur_max_sum) {
        if (!root) {
            return 0;
        }
        int left_max = check_max_sum(root->left, cur_max_sum);
        int right_max = check_max_sum(root->right, cur_max_sum);
        cur_max_sum = max(cur_max_sum, max(root->val, max(root->val + left_max + right_max,
                        max(root->val + left_max, root->val + right_max))));
        return max(root->val, max(root->val + left_max, root->val + right_max));
    }
};
