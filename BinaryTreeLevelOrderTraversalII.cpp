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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int> > ret;
        vector<int> cur_ret; 
        queue<TreeNode *> Q;
        int cur_level = 1;
        int next_level = 0;
        if (!root) {
            return ret;
        }
        Q.push(root);
        while (!Q.empty()) {
            TreeNode* cur_node = Q.front();
            Q.pop();
            cur_level--;
            cur_ret.push_back(cur_node->val);
            if (cur_node->left) {
                Q.push(cur_node->left);
                next_level++;
            }
            if (cur_node->right) {
                Q.push(cur_node->right);
                next_level++;
            }
            if (cur_level == 0) {
                ret.push_back(cur_ret);
                cur_ret.clear();
                cur_level = next_level;
                next_level = 0;
            }
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};