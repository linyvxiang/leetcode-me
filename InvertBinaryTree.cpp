/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        stack<TreeNode*> S;
        S.push(root);
        while (!S.empty()) {
            TreeNode* cur_node = S.top();
            S.pop();
            if (!cur_node) {
                continue;
            }
            swap(cur_node->left, cur_node->right);
            S.push(cur_node->left);
            S.push(cur_node->right);
        }
        return root;
    }
};
