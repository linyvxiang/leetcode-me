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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode *> node_stack;
        TreeNode* cur_node = root;
        while (!node_stack.empty() || cur_node) {
            if (cur_node) {
                node_stack.push(cur_node);
                cur_node = cur_node->left;
            } else {
                ret.push_back(node_stack.top()->val);

                cur_node = node_stack.top()->right;
                node_stack.pop();
            }
        }
        return ret;
    }
};
