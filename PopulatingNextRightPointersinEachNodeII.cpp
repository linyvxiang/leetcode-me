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
        if(!root)
            return ;
        queue<TreeLinkNode *> Q;
        int cur_count = 1, next_count = 0;
        Q.push(root);
        TreeLinkNode *prev = NULL;
        while(!Q.empty()) {
            TreeLinkNode *tmp = Q.front();
            if(tmp->left) {
                Q.push(tmp->left);
                next_count++;
            }
            if(tmp->right) {
                Q.push(tmp->right);
                next_count++;
            }
            Q.pop();
            cur_count--;
            
            if(!prev) {
                prev = tmp;
            } else {
                prev->next = tmp;
                prev = tmp;
            }
            
            if(cur_count == 0) {
                tmp->next = NULL;
                cur_count = next_count;
                next_count = 0;
                prev = NULL;
            }
        }
    }
};
