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
    void in_order(TreeNode *root, vector<int> &res) {
        if(root->left)
            in_order(root->left, res);
        res.push_back(root->val);
        if(root->right)
            in_order(root->right, res);
    }
    vector<int> inorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> V;
        if(!root)
            return V;
        in_order(root, V);
        return move(V);
    }
};
