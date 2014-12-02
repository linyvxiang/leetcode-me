#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
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
    bool isBalanced(TreeNode *root) {
		return check_balanced(root) >= 0;
    }
private:
	int abs(int a)
	{
		return a >= 0 ? a : -a;
	}
	int check_balanced(TreeNode *root)
	{
		if(!root)
			return -1;

		int left_height = check_balanced(root->left);
		if(left_height < 0)
			return -1;
		int right_height = check_balanced(root->right);
		if(right_height < 0)
			return -1;

		if(abs(left_height - right_height) > 1)
			return -1;

		return 1 + max(left_height, right_height);
	}
};
