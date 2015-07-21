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
    void flatten(TreeNode* root) {
        TreeNode* prev = NULL;
        do_flatten(root, &prev);
    }
private:
    void do_flatten(TreeNode* root, TreeNode** prev) {
        if (!root) {
            return;
        }
        if (*prev) {
            (*prev)->left = NULL;
            (*prev)->right = root;
        }
        *prev = root;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        do_flatten(left, prev);
        do_flatten(right, prev);
    }
};
