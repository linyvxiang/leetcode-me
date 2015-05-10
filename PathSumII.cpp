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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > ret;
        vector<int> cur_ret;
        do_check(root, 0, sum, cur_ret, ret);
        return ret;
    }
private:
    void do_check(TreeNode* root, int cur_sum, const int& target,
            vector<int>& cur_ret, vector<vector<int> >& ret) {
        if (!root) {
            return;
        }
        cur_sum += root->val;
        cur_ret.push_back(root->val);
        if (cur_sum == target && !root->left && !root->right) {
            ret.push_back(cur_ret);
            cur_ret.pop_back();
            return;
        }
        do_check(root->left, cur_sum, target, cur_ret, ret);
        do_check(root->right, cur_sum, target, cur_ret, ret);
        cur_ret.pop_back();
    }
};
