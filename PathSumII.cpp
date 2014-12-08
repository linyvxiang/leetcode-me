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
   vector<vector<int> > pathSum(TreeNode *root, int sum) {
	   vector<vector<int> > ret;
	   vector<int> tmp_ret;
	   if(!root)
		   return ret;
	   get_path_sum(root, 0, sum, tmp_ret, ret);
	   return ret;
   }
private:
   void get_path_sum(TreeNode *root, int cur_sum, int sum, 
		   				vector<int> &tmp_ret, vector<vector<int> > &ret)
   {
	   cur_sum += root->val;
	   tmp_ret.push_back(root->val);
	   if(!root->left && !root->right) {
		   if(cur_sum == sum)
			   ret.push_back(tmp_ret);
	   }
	   if(root->left)
		   get_path_sum(root->left, cur_sum, sum, tmp_ret, ret);
	   if(root->right)
		   get_path_sum(root->right, cur_sum, sum, tmp_ret, ret);
	   tmp_ret.pop_back();
		
   }
};
