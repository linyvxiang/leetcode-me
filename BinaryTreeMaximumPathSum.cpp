struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxPathSum(TreeNode *root) {
        int res = INT_MIN;
        int ret = get_max_path(root, res);
        return max(ret, res);
    }
private:
    int get_max_path(TreeNode *root, int &cur_max)
    {
        if(!root)
            return 0;
        int cur_sum = root->val;
        int left_max = get_max_path(root->left, cur_max);
        int right_max = get_max_path(root->right, cur_max);
        if(left_max > 0)
            cur->val += left_max;
        if(right_max > 0)
            cur->val += right_max;
        cur_max = max(cur_max, cur_sum);

        return max(root->val, max(left_max, right_max) + root->val);
    }
};
