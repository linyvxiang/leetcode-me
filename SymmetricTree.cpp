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
    bool isSymmetric(TreeNode *root) {
		if(!root)
			return true;
		return judge_symmetric(root->left, root->right);
    }
private:
	bool judge_symmetric(TreeNode *left_tree, TreeNode *right_tree)
	{
		if(!left_tree && !right_tree)
			return true;
		if(left_tree && right_tree && left_tree->val == right_tree->val)
			return judge_symmetric(left_tree->right, right_tree->left)
					&& judge_symmetric(left_tree->left, right_tree->right);
		return false;
	}
};
