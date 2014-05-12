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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int>> res;
        if(!root)
            return res;
        int cur_count = 1, next_count = 0;
        queue<TreeNode *> Q;
        vector<int> tmp_res;
        Q.push(root);
        while(!Q.empty()) {
            TreeNode *tmp = Q.front();
            Q.pop();
            cur_count--;
            tmp_res.push_back(tmp->val);
            if(tmp->left) {
                Q.push(tmp->left);
                next_count++;
            }
            if(tmp->right) {
                Q.push(tmp->right);
                next_count++;
            }
            if(cur_count == 0) {
                res.push_back(tmp_res);
                tmp_res.clear();
                cur_count = next_count;
                next_count = 0;
            }
        }
        std::reverse(res.begin(), res.end());
        return res;
        
    }
};
