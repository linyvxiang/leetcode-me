/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
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
    void check(TreeNode *prev, TreeNode *cur, TreeNode **first, TreeNode **second)
    {
        if(prev->val > cur->val) {
            if(!(*first)) {
                *first = prev;
                *second = cur;
            } else {
                *second = cur;
            }
        }
    }
    void recoverTree(TreeNode *root) {
        if(!root)
            return ;
        TreeNode *cur = root;
        TreeNode *p = NULL;
        TreeNode *first = NULL, *second = NULL;
        while(cur) {
            if(!cur->left) {
                if(!p)
                    p = cur;
                else
                    check(p, cur, &first, &second);
                p = cur;
                cur = cur->right;
            } else {
                TreeNode *prev = cur->left;
                while(prev->right && prev->right != cur)
                    prev = prev->right;
                if(!prev->right) {
                    prev->right = cur;
                    cur = cur->left;
                } else {
                    prev->right = NULL;
                    if(!p)
                        p = cur;
                    else
                        check(p ,cur, &first, &second);
                    p = cur;
                    cur = cur->right;
                }
            }
        }
        swap(first->val, second->val);
    }
};
