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
    int subtree_sum(TreeNode *root, int cur_sum) {
        if(!root)
            return cur_sum;
        cur_sum = cur_sum * 10 + root->val;
        if(root->left && root->right)
            return subtree_sum(root->left, cur_sum) + subtree_sum(root->right, cur_sum);
        if(root->left && !root->right)
            return subtree_sum(root->left, cur_sum);
        if(root->right && !root->left)
            return subtree_sum(root->right, cur_sum);
        return cur_sum;
    }
    int sumNumbers(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(!root) 
            return 0;
        if(root->left && root->right)
            return subtree_sum(root->left, root->val) + subtree_sum(root->right, root->val);
        else if(root->left && !root->right)
            return subtree_sum(root->left, root->val);
        else if(root->right && !root->left)
            return subtree_sum(root->right, root->val);
        return root->val;
    }
};
