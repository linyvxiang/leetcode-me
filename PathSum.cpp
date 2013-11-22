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
    bool find_path(TreeNode *root, int cur_sum, int target_sum) {
        cur_sum += root->val;
        if(!root->left && !root->right && cur_sum == target_sum)
            return true;
        bool left = false, right = false;
        if(root->left) {
            left = find_path(root->left, cur_sum, target_sum);
        }
        if(left)
            return true;
        if(root->right) {
            right = find_path(root->right, cur_sum, target_sum);
        }
        if(right)
            return true;
        return false;
    }
    bool hasPathSum(TreeNode *root, int sum) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(!root)
            return false;
        return find_path(root, 0, sum);
    }
};
