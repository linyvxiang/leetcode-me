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
    int minDepth(TreeNode *root) {
		if(!root)
			return 0;
		return calc_min_depth(root, 0);
    }
private:
	int cacl_min_depth(TreeNode *root, int cur_dep)
	{
		cur_dep++;
		if(root->left && root->right)
			return min(calc_min_depth(root->left, cur_dep),
						calc_min_depth(root->right, cur_dep));
		if(root->left)
			return calc_min_depth(root->left, cur_dep);
		if(root->right)
			return calc_min_depth(root->right, cur_dep);

		return cur_dep;
	}
};
