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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        if(!root)
            return res;
        stack<TreeNode *> S;
        TreeNode *cur = root;
        S.push(root);
        while(!S.empty()) {
            cur = S.top();
            if(!cur->left && !cur->right) {
                res.push_back(cur->val);
                S.pop();
            } else {
                if(cur->right) {
                    S.push(cur->right);
                    cur->right = NULL;
                }
                if(cur->left) {
                    S.push(cur->left);
                    cur->left = NULL;
                }
            }
        }
        return res;
    }
};
