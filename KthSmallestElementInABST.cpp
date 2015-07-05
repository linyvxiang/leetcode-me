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
    int kthSmallest(TreeNode* root, int k) {
        int ret;
        int cur_th = 0;
        bool find = false;
        do_find_kth(root, k, cur_th, find, ret);
        return ret;
    }
private:
    void do_find_kth(TreeNode* root, int k,
            int& cur_th, bool& find, int& ret) {
        if (!root || find) {
            return;
        }
        do_find_kth(root->left, k, cur_th, find, ret);
        cur_th++;
        if (cur_th == k) {
            ret = root->val;
            find = true;
            return;
        }
        do_find_kth(root->right, k, cur_th, find, ret);
    }
};
