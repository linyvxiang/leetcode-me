class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        if (!root) {
            return ret;
        }
        stack<TreeNode*> S;
        S.push(root);
        while (!S.empty()) {
            TreeNode*tmp = S.top();
            S.pop();
            ret.push_back(tmp->val);
            if (tmp->left) {
                S.push(tmp->left);
            }
            if (tmp->right) {
                S.push(tmp->right);
            }
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }

};
