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
    bool hasPathSum(TreeNode *root, int sum) {
		bool flag = false;
		check_path_sum(root, 0, sum, flag);
		return flag;
	}
private:
	void check_path_sum(TreeNode *root, int cur_sum, 
						int sum, bool &flag)
	{
		if(flag)
			return ;
		if(!root)
			return ;
		cur_sum += root->val;
		if(!root->left && !root->right) {
			if(cur_sum == sum)
				flag = true;
			return ;
		}
		check_path_sum(root->left, cur_sum, sum, flag);
		check_path_sum(root->right, cur_sum, sum, flag);
	}
};
