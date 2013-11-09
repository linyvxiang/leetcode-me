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
void do_postorder(TreeNode *root, vector<int> &vec) {
    if(!root)
        return ;
    do_postorder(root->left, vec);
    do_postorder(root->right, vec);
    vec.push_back(root->val);
}
    vector<int> postorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> V;
        if(!root)
            return V;
        do_postorder(root, V);
        return move(V);
    }
};
