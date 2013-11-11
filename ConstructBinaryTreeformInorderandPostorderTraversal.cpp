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
    int find_pos(vector<int> &inorder, int val, int start, int end) {
        int i;
        for(i = start; i <= end; i++)
            if(inorder[i] == val)
                return i;
    }
    void build_tree(vector<int> &inorder, int in_order_start, int in_order_end, vector<int> &postorder, int post_order_start, int post_order_end, TreeNode* &root) {
        if(in_order_start < 0 || post_order_start < 0 || in_order_start > in_order_end || post_order_start > post_order_end)
            return ;
        root = (TreeNode *)malloc(sizeof(TreeNode));
        root->val = postorder[post_order_end];
        root->left = NULL;
        root->right = NULL;
        int mid_pos = find_pos(inorder, root->val, in_order_start, in_order_end);
        int len = mid_pos - in_order_start;
        build_tree(inorder, in_order_start, mid_pos - 1, postorder, post_order_start, post_order_start + len - 1, root->left);
        build_tree(inorder, mid_pos + 1, in_order_end, postorder, post_order_start + len, post_order_end - 1 , root->right);
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        TreeNode *root = NULL;
        build_tree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, root);
        return move(root);
    }
};
