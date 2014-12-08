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
   TreeNode *sortedArrayToBST(vector<int> &num) {
	   if(num.empty())
		   return NULL;
	   return create_bst(num, 0, num.size() - 1);
   }
private:
   TreeNode *create_bst(const vector<int> &num,
		   				int start, int end)
   {
	   if(start > end)
		   return NULL;
	   if(start == end) {
		   TreeNode *root = (TreeNode *)malloc(sizeof(struct TreeNode));
		   root->val = num[start];
		   root->left = NULL;
		   root->right = NULL;
	   } else {
		   int mid = (start + end) >> 1;
		   TreeNode *root = (TreeNode *)malloc(sizeof(struct TreeNode));
		   root->val = num[mid];
		   root->left = create_bst(num, start, mid - 1);
		   root->right = create_bst(num, mid + 1, end);
		   return root;
	   }
   }
};
