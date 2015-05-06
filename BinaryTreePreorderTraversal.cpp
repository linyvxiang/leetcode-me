/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        if (!root) {
            return ret;
        }
        stack<TreeNode*> S;
        S.push(root);
        while(!S.empty()) {
            TreeNode* tmp = S.top();
            S.pop();
            ret.push_back(tmp->val);
            if (tmp->right) {
                S.push(tmp->right);
            }
            if (tmp->left) {
                S.push(tmp->left);
            }
        }
        return ret;
    }
};
