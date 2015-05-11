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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return create_tree(inorder, postorder, 0,
                inorder.size() - 1, 0, postorder.size() - 1);
    }
private:
    int find_root_pos(const vector<int>& inorder, int target, int start, int end) {
        for (int i = start; i <= end; i++) {
            if (inorder[i] == target) {
                return i;
            }
        }
        return -1;
    }
    TreeNode* create_tree(const vector<int>& inorder, vector<int>& postorder,
            int in_start, int in_end, int post_start, int post_end) {
        if (in_start > in_end) {
            return NULL;
        }
        TreeNode* root = (TreeNode *)malloc(sizeof(struct TreeNode));
        root->val = postorder[post_end];
        int root_pos = find_root_pos(inorder, root->val, in_start, in_end);
        root->left = create_tree(inorder, postorder, in_start, root_pos - 1,
                                    post_start, post_start + (root_pos - in_start - 1) );
        root->right = create_tree(inorder, postorder, root_pos + 1, in_end,
                                    post_start + (root_pos - in_start), post_end - 1);
        return root;
    }
};