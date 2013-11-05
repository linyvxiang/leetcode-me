class Solution {
public:
    void change_tree(TreeNode *root, TreeNode **prev) {
        if(!root)
            return ;
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        if(*prev) {
            (*prev)->right = root;
            (*prev)->left = NULL;
        }
        *prev = root;
        if(left)
            change_tree(left, prev);
        if(right)
            change_tree(right, prev);
    }
    void flatten(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        TreeNode **prev = (TreeNode **)malloc(sizeof(TreeNode *));
        *prev = NULL;
        change_tree(root, prev);
        free(prev);
    }
};
