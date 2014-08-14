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
    int sumNumbers(TreeNode *root) {
        return do_sum(root, 0);
    }
private:
    int do_sum(TreeNode *root, int cur_sum)
    {
        if(!root)
            return 0;
        cur_sum = cur_sum * 10 +  root->val;
        if(!root->left && !root->right)
            return cur_sum;
        return do_sum(root->left, cur_sum) 
                + do_sum(root->right, cur_sum);

    }
};
