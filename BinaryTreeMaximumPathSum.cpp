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
     int maxPathSum(TreeNode *root) {  
         int res = INT_MIN;
         int cur_max = get_max(root, res);
         return max(res, cur_max);
     }
private:
     int get_max(TreeNode *root, int &res)
     {
         if(!root)
             return 0;
         int left_max = get_max(root->left, res);
         int right_max = get_max(root->right, res);
         int cur = root->val;
         if(left_max > 0)
             cur += left_max;
         if(right_max > 0)
             cur += right_max;
         res = max(cur, res);

         return max(root->val, max(left_max, right_max) + root->val);
     }
};
