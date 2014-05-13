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
    void in_order_traversal(TreeNode *root, vector<TreeNode *> &res)
    {
        if(!root)
            return ;
        in_order_traversal(root->left, res);
        res.push_back(root);
        in_order_traversal(root->right, res);
    }
    void recoverTree(TreeNode *root) {
        vector<TreeNode *> res;
        if(!root)
            return;
        in_order_traversal(root, res);
        int i;
        for(i = 0; i < res.size() - 1; i++) {
            if(res[i]->val > res[i + 1]->val) { // node i is the wrong node, work from the end to find another wrong node
                int j;
                for(j = res.size() - 1; j > i; j--) {
                    if(res[j]->val < res[i]->val) {
                        int tmp = res[i]->val;
                        res[i]->val = res[j]->val;
                        res[j]->val = tmp;
                        return;
                    }
                }
            }
                
        }
        return ;
    }
};
