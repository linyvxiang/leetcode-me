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
    vector<vector<int> > levelOrder(TreeNode *root) {
		vector<vector<int> > ret;
		vector<int> tmp_ret;
		if(!root)
			return ret;
		queue<TreeNode *> Q;
		Q.push(root);
		int cur_level_count = 1, next_level_count = 0;
		while(!Q.empty()) {
			TreeNode *cur_node = Q.front();
			Q.pop();
			tmp_ret.push_back(cur_node->val);
			if(cur_node->left) {
				Q.push(cur_node->left);
				next_level_count++;
			}
			if(cur_node->right) {
				Q.push(cur_node->right);
				next_level_count++;
			}
			cur_level_count--;
			if(cur_level_count == 0) {
				ret.push_back(tmp_ret);
				tmp_ret.clear();
				cur_level_count = next_level_count;
				next_level_count = 0;
			}
		}
		return ret;
    }
};
