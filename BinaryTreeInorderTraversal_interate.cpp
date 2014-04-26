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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        if(!root)
            return res;
        stack<TreeNode *> S;
        TreeNode *cur = root;
        while(!S.empty() || cur) {
            if(cur) {
                S.push(cur);
                cur = cur->left;
            } else {
                res.push_back(S.top()->val);
                cur = S.top()->right;
                S.pop();
            }
        }
        return res;
    }
};
