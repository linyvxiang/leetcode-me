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
    bool judge_left_right_child(TreeNode *l, TreeNode *r)
    {
        if(!l && !r)
            return true;
        if(l && !r || r && !l)
            return false;
        if(l->val != r->val)
            return false;
        return judge_left_right_child(l->left, r->right) && judge_left_right_child(l->right, r->left);
    }
    bool isSymmetric(TreeNode *root) {
        if(!root)
            return true;
        return judge_left_right_child(root->left, root->right);
    }
};
