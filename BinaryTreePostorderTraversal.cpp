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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        if (!root) {
            return ret;
        }
        stack<TreeNode*> node_stack;
        node_stack.push(root);
        while (!node_stack.empty()) {
            TreeNode* cur_node = node_stack.top();
            node_stack.pop();
            ret.push_back(cur_node->val);
            if (cur_node->left) {
                node_stack.push(cur_node->left);
            }
            if (cur_node->right) {
                node_stack.push(cur_node->right);
            }
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
