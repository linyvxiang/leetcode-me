class Solution {
public:
    bool judge_subtree(TreeNode *left_node, TreeNode *right_node) {
        if(!left_node && !right_node)
            return true;
        if(!left_node && right_node || left_node && !right_node)
            return false;
        if(left_node->val != right_node->val)
            return false;
        return judge_subtree(left_node->left, right_node->right) && judge_subtree(left_node->right, right_node->left);
    }
    bool isSymmetric(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(!root)
            return true;
        return judge_subtree(root->left, root->right);
    }
};
