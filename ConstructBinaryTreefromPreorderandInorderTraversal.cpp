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
    int find_pos(vector<int> inorder, int val, int start, int end) {
        int i;
        for(i = start; i <= end; i++)
            if(inorder[i] == val)
                return i;
    }
    void build_tree(vector<int> &preorder, int pre_order_start, int pre_order_end, vector<int> &inorder, int in_order_start, int in_order_end, TreeNode* &root) {
        if(pre_order_start < 0 || in_order_start < 0 || pre_order_start > pre_order_end || in_order_start > in_order_end)
            return ;
        root = (TreeNode *)malloc(sizeof(TreeNode));
        root->val = preorder[pre_order_start];
        root->left = NULL;
        root->right = NULL;
        int mid_pos = find_pos(inorder, root->val, in_order_start, in_order_end);
        int len = mid_pos - in_order_start;
        build_tree(preorder, pre_order_start + 1, pre_order_start + len, inorder, in_order_start, mid_pos - 1, root->left);
        build_tree(preorder, pre_order_start + len + 1, pre_order_end, inorder, mid_pos + 1, in_order_end, root->right);
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        TreeNode *root = NULL;
        build_tree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, root);
        return move(root);
    }
};
