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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return create_tree(preorder, inorder, 0, preorder.size() - 1,
                            0, inorder.size() - 1);
    }
private:
    int find_root_pos(const vector<int>& nums, int target, int start, int end) {
        for (int i = start; i <= end; i++) {
            if (nums[i] == target) {
                return i;
            }
        }
        return -1;
    }
    TreeNode* create_tree(const vector<int>& preorder, const vector<int>& inorder,
            int pre_start, int pre_end, int in_start, int in_end) {
        if (pre_start > pre_end) {
            return NULL;
        }
        TreeNode* root = (TreeNode *)malloc(sizeof(struct TreeNode));
        root->val = preorder[pre_start];
        int root_pos = find_root_pos(inorder, root->val, in_start, in_end);
        root->left = create_tree(preorder, inorder,
                                 pre_start + 1, pre_start + root_pos - in_start,
                                 in_start, root_pos - 1);
        root->right = create_tree(preorder, inorder,
                                  pre_start + root_pos - in_start + 1, pre_end,
                                  root_pos + 1, in_end);
        return root;
    }
};