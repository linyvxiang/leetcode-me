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
        vector<int> ret;
        if(!root)
            return ret;
        TreeNode *cur_node = root;
        stack<TreeNode *> S;
        while(cur_node || !S.empty()) {
            if(cur_node) {
                S.push(cur_node);
                cur_node = cur_node->left;
            } else {
                cur_node = S.top()->right;
                ret.push_back(S.top()->val);
                S.pop();
            }
        }
        return ret;
    }
};
