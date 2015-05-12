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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > ret;
        vector<int> cur_ret;
        if (!root) {
            return ret;
        }
        queue<TreeNode *> Q;
        Q.push(root);
        int cur_level = 1;
        int next_level = 0;
        int level_num = 0;
        while (!Q.empty()) {
            TreeNode* cur_node = Q.front();
            Q.pop();
            cur_ret.push_back(cur_node->val);
            cur_level--;
            if (cur_node->left) {
                Q.push(cur_node->left);
                next_level++;
            }
            if (cur_node->right) {
                Q.push(cur_node->right);
                next_level++;
            }
            if (!cur_level) {
                cur_level = next_level;
                next_level = 0;
                if (level_num % 2 == 1) {
                    reverse(cur_ret.begin(), cur_ret.end());
                }
                level_num++;
                ret.push_back(cur_ret);
                cur_ret.clear();
            }
        }
        return ret;
    }
};