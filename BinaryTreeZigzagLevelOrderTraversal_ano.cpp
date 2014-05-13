/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> res;
        if(!root)
            return res;
        queue<TreeNode *> Q;
        vector<int> tmp_res;
        int cur_count = 1, next_count = 0, c_l = 0;
        Q.push(root);
        while(!Q.empty()) {
            TreeNode *tmp = Q.front();
            if(tmp->left) {
                Q.push(tmp->left);
                next_count++;
            }
            if(tmp->right) {
                Q.push(tmp->right);
                next_count++;
            }
            Q.pop();
            cur_count--;
            tmp_res.push_back(tmp->val);
            if(cur_count == 0) {
                if(c_l % 2 == 1) {

                    reverse(tmp_res.begin(), tmp_res.end());
                }
                c_l++;
                res.push_back(tmp_res);
                tmp_res.clear();
                cur_count = next_count;
                next_count = 0;
            }
        }
        return res;
    }
};
