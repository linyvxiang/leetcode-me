/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void do_calc_sum(TreeNode *root, int &sum, int cur_num)
    {
        cur_num = cur_num * 10 + root->val;
        if(root->left == NULL && root->right == NULL)
            sum += cur_num;
        if(root->left)
            do_calc_sum(root->left, sum, cur_num);
        if(root->right)
            do_calc_sum(root->right, sum, cur_num);
    }
    int sumNumbers(TreeNode *root) {
        int sum = 0;
        int cur_num = 0;
        if(!root)
            return 0;
        do_calc_sum(root, sum, cur_num);
        return sum;
    }
};
