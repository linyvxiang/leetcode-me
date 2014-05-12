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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int>> res;
        if(!root)
            return res;
        queue<TreeNode *> Q;
        Q.push(root);
        vector<int> tmp_res;
        int cur_count = 1, next_count = 0;
        while(!Q.empty()) {
            TreeNode *tmp = Q.front();
            tmp_res.push_back(tmp->val);
            Q.pop();
           
            if(tmp->left) {
                Q.push(tmp->left);
                next_count++;
            }
            if(tmp->right) {
                Q.push(tmp->right);
                next_count++;
            }
            cur_count--;
            if(cur_count == 0) {
                res.push_back(tmp_res);
                tmp_res.clear();
                cur_count = next_count;
                next_count = 0;
            }
        }
        return res;
    }
};
