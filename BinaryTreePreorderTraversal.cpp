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
    void do_pre_order(TreeNode *root, vector<int> &vec) {
        if(!root)
            return ;
        vec.push_back(root->val);
        do_pre_order(root->left, vec);
        do_pre_order(root->right, vec);
    }
    vector<int> preorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> V;
        if(!root)
            return V;
        do_pre_order(root, V);
        return move(V);
    }
};
