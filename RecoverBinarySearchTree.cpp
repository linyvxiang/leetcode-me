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
    void in_order_traversal(TreeNode *root, TreeNode **prev, TreeNode **first,
                                                            TreeNode **last)
    {
        if(!root)
            return ;
        if(root->left)
            in_order_traversal(root->left, prev, first, last);
        if(*prev && root->val < (*prev)->val) {
            if(!(*first)) {
                *first = *prev;
                *last = root;
            }
            else
                *last = root;
        }
        *prev = root;
        if(root->right)
            in_order_traversal(root->right, prev, first, last);

    }
    void recoverTree(TreeNode *root) {
        if(!root)
            return ;
        TreeNode *prev = NULL, *first = NULL, *last = NULL;

        in_order_traversal(root, &prev, &first, &last);
        swap(first->val, last->val);

        return ;
    }
};
