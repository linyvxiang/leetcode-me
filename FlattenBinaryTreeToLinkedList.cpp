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
   void do_flatten(TreeNode *root, TreeNode **prev)
   {
        if(!root)
            return ;
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        if(!(*prev))
            *prev = root;
        else {
            (*prev)->right = root;
            (*prev)->left = NULL;
            *prev = root;
        }
        do_flatten(left, prev);
        do_flatten(right, prev);
        
   }
    void flatten(TreeNode *root) {
        TreeNode *prev = NULL;
        if(!root)
            return;
        do_flatten(root, &prev);
    }
};
