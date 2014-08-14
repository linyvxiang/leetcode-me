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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        TreeNode *root = NULL;
        create_tree(num, 0, num.size() - 1, root);
        return root;
    }
private:
    void create_tree(vector<int> &num, int start_pos, int end_pos, TreeNode* &root)
    {
        if(start_pos > end_pos)
            return ;
        root = (TreeNode *)malloc(sizeof(struct TreeNode));
        memset(root, 0, sizeof(struct TreeNode));
        int mid = (start_pos + end_pos) >> 1;
        root->val = num[mid];
        create_tree(num, start_pos, mid - 1, root->left);
        create_tree(num, mid + 1, end_pos, root->right);
    }
};
