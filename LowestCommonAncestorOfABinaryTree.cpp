class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == p || root == q) {
            return root;
        }
        bool p_left = find_node(root->left, p);
        bool q_left = find_node(root->left, q);
        if (p_left && q_left) {
            return lowestCommonAncestor(root->left, p, q);
        } else if (!p_left && !q_left) {
            return lowestCommonAncestor(root->right, p, q);
        } else {
            return root;
        }
    }
private:
    bool find_node(TreeNode* root, TreeNode* target) {
        if (!root) {
            return false;
        } else if (root == target) {
            return true;
        }
        return find_node(root->left, target) ||
                find_node(root->right, target);
    }
};
