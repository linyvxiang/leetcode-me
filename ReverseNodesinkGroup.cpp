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
	ListNode *do_k_reverse(ListNode *start, int k, ListNode *end)
	{
		ListNode HEAD(0);
		HEAD.next = NULL;
		ListNode *cur = start, *tmp;
		while(cur != end) {
			tmp = cur->next;
			cur->next = HEAD.next;
			HEAD.next = cur;
			cur = tmp;
		}
		start->next = end;		
		return HEAD.next;
	}
	ListNode *reverseKGroup(ListNode *head, int k) {
		if(!head)
			return head;
		ListNode HEAD(0);
		HEAD.next = head;
		ListNode *cur = head, *pre = &HEAD;
		while(cur) {
			int i;
			for(i = 0; i < k - 1; i++) {
				cur = cur->next;
				if(!cur)
					return HEAD.next;
			}
			ListNode *tmp_pre = pre->next;
			pre->next = do_k_reverse(pre->next, k, cur->next);
			pre = tmp_pre;
			cur = pre->next;
		}
		return HEAD.next;
	}
};
