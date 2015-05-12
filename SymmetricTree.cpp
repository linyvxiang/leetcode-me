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
    bool isSymmetric(TreeNode* root) {
        if (!root) {
            return true;
        }
        return check_symmetric(root->left, root->right);
    }
private:
    bool check_symmetric(TreeNode* p, TreeNode* q) {
        if (!p && !q) {
            return true;
        } else if (p && !q || !p && q) {
            return false;
        } else {
            if (p->val != q->val) {
                return false;
            }
            return check_symmetric(p->left, q->right)
                    && check_symmetric(p->right, q->left);
        }
    }
};