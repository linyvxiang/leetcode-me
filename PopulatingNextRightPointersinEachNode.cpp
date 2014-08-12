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
				return;
			queue<TreeLinkNode *> q;
			TreeLinkNode *prev = NULL, *cur = root;
			int cur_level_len = 1, next_level_len = 0;
			q.push(root);
			while(!q.empty()) {
				if((q.front())->left) {
					q.push((q.front())->left);
					next_level_len++;
				}
				if((q.front()->right)) {
					q.push((q.front())->right);
					next_level_len++;
				}

				if(prev)
					prev->next = q.front();
				cur_level_len--;
				if(!cur_level_len) {
					q.front()->next = NULL;
					cur_level_len = next_level_len;
					next_level_len = 0;
					prev  = NULL;
				} else {
					prev = q.front();
				}
				q.pop();
			}	
		}
};
