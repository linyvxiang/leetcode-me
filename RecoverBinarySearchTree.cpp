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
    void recoverTree(TreeNode* root) {
        do_recovery_tree(root);
    }
private:
    void do_recovery_tree(TreeNode *root) {
        TreeNode* cur_node = root;
        TreeNode* prev = NULL;
        TreeNode* first = NULL;
        TreeNode* second = NULL;
        while (cur_node) {
            if (!cur_node->left) {
                // visit cur
                if (!prev) {
                    prev = cur_node;
                } else {
                    if (prev->val > cur_node->val) {
                        if (!first) {
                            first = prev;
                            second = cur_node;
                        } else {
                            second = cur_node;
                        }
                    }
                    prev = cur_node;
                }
                cur_node = cur_node->right;
            } else {
                TreeNode* tmp = cur_node->left;
                while (tmp->right && tmp->right != cur_node) {
                    tmp = tmp->right;
                }
                if (!tmp->right) {
                    tmp->right = cur_node;
                    cur_node = cur_node->left;
                } else {
                    tmp->right = NULL;
                    //visit cur_node
                    if (!prev) {
                        prev = cur_node;
                    } else {
                        if (prev->val > cur_node->val) {
                            if (!first) {
                                first = prev;
                                second = cur_node;
                            } else {
                                second = cur_node;
                            }
                        }
                        prev = cur_node;
                    }
                    cur_node = cur_node->right;
                }
            }
        }
        swap(first->val, second->val);
    }
};