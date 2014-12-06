/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
   TreeNode *sortedListToBST(ListNode *head) {
	   if(!head)
		   return NULL;
	   ListNode *cur_node = head;
	   int len = get_len(head);
	   return create_bst(cur_node, 0, len - 1);
   }
private:
   int get_len(ListNode *root)
   {
	   int ret = 0;
	   ListNode *cur_node = root;
	   while(cur_node) {
		   ret++;
		   cur_node = cur_node->next;
	   }
	   return ret;
   }
   TreeNode *create_bst(ListNode* &cur_node, 
		   					 int start, int end)
   {
	   if(start > end)
		   return NULL;
	   if(start == end) {
		   TreeNode *root = (TreeNode *)malloc(sizeof(struct TreeNode));
		   root->val = cur_node->val;
		   root->left = root->right = NULL;
		   cur_node = cur_node->next;
		   return root;
	   } else {
		   TreeNode *root = (TreeNode *)malloc(sizeof(struct TreeNode));
		   root->left = create_bst(cur_node, start, (start + end) / 2 - 1);
		   root->val = cur_node->val;
		   cur_node = cur_node->next;
		   root->right = create_bst(cur_node, (start + end) / 2 + 1, end);
		   return root;
	   }
   }
};
