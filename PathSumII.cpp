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
    void find_path(TreeNode *root, int cur_sum, int target_sum, vector<vector<int>> &final_res, vector<int> &cur_res) {
        cur_res.push_back(root->val);
        cur_sum += root->val;
        if(!root->left && !root->right && cur_sum == target_sum) {
            final_res.push_back(cur_res);
        }
        if(root->left) {
            find_path(root->left, cur_sum, target_sum, final_res, cur_res);
        }
        if(root->right) {
            find_path(root->right, cur_sum, target_sum, final_res, cur_res);
        }
        cur_res.pop_back();
        
    }
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<vector<int>> V;
        if(!root)
            return V;
        vector<int> temp_res;
        find_path(root, 0, sum, V, temp_res);
        return move(V);
    }
};
