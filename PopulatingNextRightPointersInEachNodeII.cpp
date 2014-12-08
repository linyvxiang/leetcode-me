#include <queue>
using namespace std;
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
};
class Solution {
	public:
		void connect(TreeLinkNode *root) {
			if(!root)
				return ;
			queue<TreeLinkNode *> Q;
			Q.push(root);
			int cur_level_count = 1, next_level_count = 0;
			TreeLinkNode *prev = NULL;
			while(!Q.empty()) {
				TreeLinkNode *cur_node = Q.front();
				Q.pop();
				if(prev == NULL)
					prev = cur_node;
				cur_level_count--;
				prev->next = cur_node;

				if(cur_node->left) {
					Q.push(cur_node->left);
					next_level_count++;
				}
				if(cur_node->right) {
					Q.push(cur_node->right);
					next_level_count++;
				}

				if(cur_level_count == 0) {
					cur_node->next = NULL;
					prev = NULL;
					cur_level_count = next_level_count;
					next_level_count = 0;
				} else {
					prev = cur_node;
				}
				
			}
		}
};
