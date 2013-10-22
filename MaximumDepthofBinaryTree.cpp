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
    int maxDepth(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(!root)
            return 0;
        if(!root->left && !root->right)
            return 1;
        int left_max = INT_MIN;
        int right_max = INT_MIN;
        if(root->left)
            left_max = maxDepth(root->left);
        if(root->right)
            right_max = maxDepth(root->right);
        return max(left_max, right_max) + 1;
    }
};
