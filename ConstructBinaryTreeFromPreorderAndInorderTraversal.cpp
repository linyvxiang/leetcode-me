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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		if(preorder.empty())
			return NULL;
		return do_build_tree(preorder, inorder, 0, preorder.size() - 1,
												0, inorder.size() - 1);        
    }
private:
	int find_inorder(const vector<int> &inorder, int start, int end, int target)
	{
		int i;
		for(i = start; i <= end; i++)
			if(inorder[i] == target)
				return i;
	}
	TreeNode *do_build_tree(const vector<int> &preorder, 
							const vector<int> &inorder, 
							int preorder_start, int preorder_end,
							int inorder_start, int inorder_end)
	{
		if(preorder_start > preorder_end)
			return NULL;

		TreeNode *root = (TreeNode *)malloc(sizeof(struct TreeNode));
		root->val = preorder[preorder_start];
		root->left = root->right = NULL;
		int pos = find_inorder(inorder, inorder_start, inorder_end, root->val);

		root->left = do_build_tree(preorder, inorder, preorder_start + 1, 
						preorder_start + pos - inorder_start,
						inorder_start, pos - 1); 
		
		root->right = do_build_tree(preorder, inorder, 
									preorder_end - inorder_end + pos + 1,
									preorder_end, pos + 1, inorder_end);

		return root;
	}
};
