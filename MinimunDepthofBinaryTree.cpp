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
    int minDepth(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(!root)
            return 0;
        if(root->left == NULL && root->right == NULL)
            return 1;
            
        int left_min = INT_MAX;
        if(root->left)
            left_min = minDepth(root->left) + 1;
        int right_min = INT_MAX;
        if(root->right)
            right_min = minDepth(root->right) + 1;
        
        return min(left_min, right_min);
        
    }
};
