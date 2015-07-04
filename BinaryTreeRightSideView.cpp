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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        if (!root) {
            return ret;
        }
        queue<TreeNode*> Q;
        Q.push(root);
        int cur_level = 1;
        int next_level = 0;
        while (!Q.empty()) {
            TreeNode *cur_node = Q.front();
            Q.pop();
            if (cur_node->left) {
                Q.push(cur_node->left);
                next_level++;
            }
            if (cur_node->right) {
                Q.push(cur_node->right);
                next_level++;
            }
            cur_level--;
            if (cur_level == 0) {
                ret.push_back(cur_node->val);
                swap(next_level, cur_level);
            }
        }
        return ret;
    }
};
