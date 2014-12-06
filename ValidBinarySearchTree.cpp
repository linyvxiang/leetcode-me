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
    bool isValidBST(TreeNode *root) {
		return judge_valid_bst(root, (long long)INT_MIN - 1, (long long)INT_MAX + 1);
    }
private:
	bool judge_valid_bst(TreeNode *root, long long min_val, long long max_val)
	{
		if(!root)
			return true;
		if(root->val <= min_val || root->val >= max_val)
		    return false;
		return judge_valid_bst(root->left, min_val, root->val)
					&& judge_valid_bst(root->right, root->val, max_val);
	}
};
