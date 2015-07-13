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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        if (!root) {
            return ret;
        }
        stack<TreeNode *> S;
        S.push(root);
        while (!S.empty()) {
            TreeNode* cur_node = S.top();
            S.pop();
            ret.push_back(cur_node->val);
            if (cur_node->right) {
                S.push(cur_node->right);
            }
            if (cur_node->left) {
                S.push(cur_node->left);
            }
        }
        return ret;
    }
};
