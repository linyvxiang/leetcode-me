class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == p || root == q) {
            return root;
        }
        bool p_left = find_node(p, root->left);
        bool q_left = find_node(q, root->left);
        if (p_left && q_left) {
            return lowestCommonAncestor(root->left, p, q);
        } else if (!p_left && !q_left) {
            return lowestCommonAncestor(root->right, p, q);
        } else {
            return root;
        }
    }
private:
    bool find_node(TreeNode* target, TreeNode* root) {
        if (!root) {
            return false;
        }
        if (root == target) {
            return root;
        } else if (root->val > target->val) {
            return find_node(target, root->left);
        } else {
            return find_node(target, root->right);
        }
    }
};
