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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > res;
        vector<int> tmp_res;
        if(!root)
            return res;
        do_judge_path(root, 0, sum, res, tmp_res);
        return res;
    }
private:
    void do_judge_path(TreeNode *root, int cur_sum, int target_sum, 
                        vector<vector<int> > &res, vector<int> &tmp_res)
    {
        cur_sum += root->val;
        tmp_res.push_back(root->val);
        if(!root->left && !root->right) {
            if(cur_sum == target_sum)
                res.push_back(tmp_res);
        }
        if(root->left)
            do_judge_path(root->left, cur_sum, target_sum, res, tmp_res);
        if(root->right)
            do_judge_path(root->right, cur_sum, target_sum, res, tmp_res);
        tmp_res.pop_back();
    }
};
