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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        if(!root)
            return res;
        stack<TreeNode *> S;
        TreeNode *cur = root;
        S.push(cur);
        while(!S.empty()) {
            res.push_back(S.top()->val);
            cur = S.top();
            S.pop();
            if(cur->right)
                S.push(cur->right);
            if(cur->left)
                S.push(cur->left);
        }
        return res;
    }
};
