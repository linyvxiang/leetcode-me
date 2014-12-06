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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		if(inorder.empty())
			return NULL;
		return do_build_tree(inorder, postorder, 0, inorder.size() - 1, 
											0, postorder.size() - 1);
	}
private:
	int find_inorder(const vector<int> &inorder, int start, int end, int target)
	{
		int i;
		for(i = start; i <= end; i++)
			if(inorder[i] == target)
				return i;
	}

	TreeNode *do_build_tree(const vector<int> &inorder, 
							const vector<int> &postorder,
							int inorder_start, int inorder_end,
							int postorder_start, int postorder_end)
	{
		if(inorder_start > inorder_end)
			return NULL;
		TreeNode *root = (TreeNode *)malloc(sizeof(struct TreeNode));
		root->left = root->right = NULL;
		root->val = postorder[postorder_end];
		int pos = find_inorder(inorder, inorder_start, inorder_end, root->val);

		root->left = do_build_tree(inorder, postorder, inorder_start, 
											pos - 1, postorder_start,
									postorder_start + pos - 1 - inorder_start);

		root->right = do_build_tree(inorder, postorder, pos + 1, inorder_end,
											postorder_end - inorder_end + pos, 
											postorder_end - 1);

		return root;
	}
};
