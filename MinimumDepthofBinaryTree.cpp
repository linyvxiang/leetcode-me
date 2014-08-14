/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
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
    int minDepth(const TreeNode *root) {
        if(!root)
            return 0;
        int min_depth = INT_MAX;
        tree_depth(root, 0, min_depth);
        return min_depth;
    }
private:
    void tree_depth(const TreeNode *root, int cur_depth, int &min_depth)
    {
        cur_depth++;
        if(!root->left && !root->right) {
            if(cur_depth < min_depth)
                min_depth = cur_depth;
            return ;
        }
        if(root->left)
            tree_depth(root->left, cur_depth, min_depth);
        if(root->right)
            tree_depth(root->right, cur_depth, min_depth);
    }
};
