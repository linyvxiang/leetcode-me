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
    void create_bst_tree(int start, int end, vector<int> &num, TreeNode **root)
    {
        if(start > end)
            return ;
        *root = (TreeNode *)malloc(sizeof(struct TreeNode));
        memset(*root, 0, sizeof(struct TreeNode));
        int mid = (start + end) >> 1;
        (*root)->val = num[mid];
        create_bst_tree(start, mid - 1, num, &((*root)->left));
        create_bst_tree(mid + 1, end, num, &((*root)->right));
    }
    TreeNode *sortedArrayToBST(vector<int> &num) {
        if(num.size() == 0)
            return NULL;
        TreeNode *root = NULL;
        create_bst_tree(0, num.size() - 1, num, &root);
        return root;
    }
};
