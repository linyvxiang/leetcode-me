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
    void recoverTree(TreeNode *root) {
        TreeNode *cur = root, *first_node = NULL, *second_node = NULL, *pre = NULL;
        while(cur) {
            if(!cur->left) {
                if(pre && pre->val > cur->val) {
                    if(!first_node) {
                        first_node = pre;
                        second_node = cur;
                    } else {
                        second_node = cur;
                    }
                }
                pre = cur;
                cur = cur->right;
            } else {
                TreeNode *pre_node = cur->left;
                while(pre_node->right && pre_node->right != cur)
                    pre_node = pre_node->right;
                if(pre_node->right == NULL) {
                    pre_node->right = cur;
                    cur = cur->left;
                } else {
                    pre_node->right = NULL;
                    if(pre && pre->val > cur->val) {
                        if(!first_node) {
                            first_node = pre;
                            second_node = cur;
                        } else {
                            second_node = cur;
                        }
                    }
                    pre = cur;
                    cur = cur->right;
                }
            }
        }
        if(first_node && second_node) {
            int tmp = first_node->val;
            first_node->val = second_node->val;
            second_node->val = tmp;
        }
    }
};
