/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
	   if(!head)
		   return head;

       ListNode HEAD(0); 
	   HEAD.next = NULL;
	   ListNode *cur_node = head;
	   while(cur_node) {
		   ListNode *tmp = cur_node;
		   cur_node = cur_node->next;
		   tmp->next = NULL;
		   insert(tmp, HEAD);
	   }

	   return HEAD.next;
    }
private:
	void insert(ListNode *node_to_insert, ListNode &HEAD)
	{
		if(HEAD.next == NULL) {
			//empty now
			HEAD.next = node_to_insert;
		} else {
			ListNode *prev = &HEAD;
			ListNode *cur = HEAD.next;
			while(cur && cur->val < node_to_insert->val) {
				cur = cur->next;
				prev = prev->next;
			}
			node_to_insert->next = prev->next;
			prev->next = node_to_insert;
		}
	}
};
