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
    bool hasPathSum(TreeNode *root, int sum) {
        return check_path(root, 0);
    }
private:
    bool check_path(TreeNode *root, int cur_sum, int target_sum)
        if(!root)
            return false;
        cur_sum += root->val;
        if(!root->left && !root->right)
            return cur_sum == target_sum;
        if(root->left)
            if(check_path(root->left, cur_sum, target))
                return true;
        if(!root->right)
            return false;
        return check_path(root->right, cur_sum, target);
    }
};

