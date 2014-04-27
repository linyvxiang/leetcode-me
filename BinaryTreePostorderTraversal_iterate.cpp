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
        S.push(root);
        TreeNode *cur;
        while(!S.empty()) {
            cur = S.top();
            S.pop();
            res.push_back(cur->val);
            if(cur->left)
                S.push(cur->left);
            if(cur->right)
                S.push(cur->right);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
