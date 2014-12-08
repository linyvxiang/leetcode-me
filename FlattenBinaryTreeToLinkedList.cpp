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
		void flatten(TreeNode *root) {
			if(!root)
				return ;
			TreeNode *pre_node = NULL;
			do_flatten(root, &pre_node);
		}
	private:
		void do_flatten(TreeNode *cur_node, TreeNode **pre_node)
		{
			if(!cur_node)
				return ;
			if(*pre_node) {
				(*pre_node)->left = NULL;
				(*pre_node)->right = cur_node;
			}
			*pre_node = cur_node;
			TreeNode *left = cur_node->left;
			TreeNode *right = cur_node->right;
			do_flatten(left, pre_node);
			do_flatten(right, pre_node);
		}
};
