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
    void create_tree(int start_pos, int end_pos, TreeNode* &root, vector<int> &num) {
        if(end_pos < 0 || start_pos > end_pos)
            return;
        root = (TreeNode *)malloc(sizeof(TreeNode));
        int mid = (start_pos + end_pos) >> 1;
        root->val = num[mid];
        root->left = NULL;
        root->right = NULL;
        create_tree(start_pos, mid - 1, root->left, num);
        create_tree(mid + 1, end_pos, root->right, num);
    }
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(num.size() == 0)
            return NULL;
        TreeNode *root = NULL;
        create_tree(0, num.size() - 1, root, num);
        return root;
    }
};
