/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) {
            return;
        }
        queue<TreeLinkNode*> Q;
        Q.push(root);
        int cur_level = 1;
        int next_level = 0;
        TreeLinkNode* prev = NULL;
        while (!Q.empty()) {
            TreeLinkNode* cur = Q.front();
            Q.pop();
            if (prev != NULL) {
                prev->next = cur;
                prev = cur;
            } else {
                prev = cur;
            }
            if (cur->left) {
                Q.push(cur->left);
                next_level++;
            }
            if (cur->right) {
                Q.push(cur->right);
                next_level++;
            }
            cur_level--;
            if (!cur_level) {
                cur_level = next_level;
                next_level = 0;
                cur->next = NULL;
                prev = NULL;
            }
        }
    }
};