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
    void recoverTree(TreeNode *root) {
		do_recover_tree(root);
	}
private:
	void do_recover_tree(TreeNode *root)
	{
		if(!root)
			return ;
		TreeNode *pre = NULL, *cur = root, *first = NULL, *second = NULL;
		while(cur) {
			if(!cur->left) {
				//visit cur;
				if(pre && pre->val > cur->val) {
					if(!first) {
						first = pre;
						second = cur;
					} else {
						second = cur;
					}
				}
				pre = cur;
				cur = cur->right;
			} else {
				TreeNode *tmp = cur->left;
				while(tmp->right && tmp->right != cur)
					tmp = tmp->right;
				if(!tmp->right) {
					tmp->right = cur;
					cur = cur->left;
				} else {
					tmp->right = NULL;
					//visit cur
					if(pre && pre->val > cur->val) {
						if(!first) {
							first = pre;
							second = cur;
						} else {
							second = cur;
						}
					}
					pre = cur;
					cur = cur->right;
				}
			}
		}
		swap(first->val, second->val);
	}
};
