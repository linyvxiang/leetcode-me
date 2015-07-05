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
    int countNodes(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int left_height = 0;
        int right_height = 0;
        int height = 0;
        TreeNode* left_node = root->left;
        TreeNode* right_node = root->right;
        while (left_node) {
            left_height++;
            left_node = left_node->left;
        }
        while (right_node) {
            right_height++;
            right_node = right_node->right;
        }
        if (left_height == right_height) {
            return 1 + 2 * ((1 << left_height) - 1);
        }
        return 1 + countNodes(root->left) +
                countNodes(root->right);
    }
};
