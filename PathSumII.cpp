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
    void do_judge(vector<vector<int>> &res, vector<int> &tmp_res, TreeNode *root, int left_sum)
    {
        left_sum -= root->val;
        tmp_res.push_back(root->val);
        if(root->left == NULL && root->right == NULL) {
            if(left_sum == 0) {
                res.push_back(tmp_res);
            }
        }
        
        if(root->left)
            do_judge(res, tmp_res, root->left, left_sum);
        if(root->right)
            do_judge(res, tmp_res, root->right, left_sum);
            
        tmp_res.pop_back();
        
    }
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int>> res;
        if(!root)
            return res;
        vector<int> tmp_res;
        do_judge(res, tmp_res, root, sum);
        return move(res);
    }
};
