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
    bool isValidBST(TreeNode *root)
    {
        return do_judge(root, INT_MIN, INT_MAX);
    }
private:
    bool do_judge(TreeNode *root, int left_bound, int right_bound)
    {
        if(!root)
            return true;
        if(root->val <= left_bound || root->val >= right_bound)
            return false;
        return do_judge(root->left, left_bound, root->val)
                && do_judge(root->right, root->val, right_bound);
    }
};
