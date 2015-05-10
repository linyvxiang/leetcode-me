/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        bool found = false;
        do_check(root, 0, sum, found);
        return found;
    }
private:
    void do_check(TreeNode* root, int cur_sum, const int& target, bool& found) {
        if (!root || found) {
            return;
        }
        cur_sum += root->val;
        if (cur_sum == target && !root->left && !root->right) {
            found = true;
            return;
        }
        do_check(root->left, cur_sum, target, found);
        do_check(root->right, cur_sum, target, found);
    }
};