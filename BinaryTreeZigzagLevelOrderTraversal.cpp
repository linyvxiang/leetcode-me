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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
		vector<vector<int> > ret;
		vector<int> tmp_ret;
		if(!root)
			return ret;
		do_level_order_traversal(root, tmp_ret, ret);
		return ret;
    }
private:
	void do_level_order_traversal(TreeNode *root, 
									vector<int> &tmp_ret,
									vector<vector<int> > &ret)
	{
		queue<TreeNode *> Q;
		Q.push(root);	
		int cur_level_count = 1, cur_level_num = 1, next_level_count = 0;
		while(!Q.empty()) {
			TreeNode *tmp = Q.front();
			Q.pop();
			tmp_ret.push_back(tmp->val);
			cur_level_count--;
			if(tmp->left) {
				Q.push(tmp->left);
				next_level_count++;
			}
			if(tmp->right) {
				Q.push(tmp->right);
				next_level_count++;
			}
			if(cur_level_count == 0) {
				if(cur_level_num % 2 == 0)
					reverse(tmp_ret.begin(), tmp_ret.end());
				ret.push_back(tmp_ret);
				tmp_ret.clear();
				cur_level_count = next_level_count;
				next_level_count = 0;
				cur_level_num++;
			}
		}
	}
};
