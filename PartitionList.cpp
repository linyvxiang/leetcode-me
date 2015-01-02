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
    ListNode *partition(ListNode *head, int x) {
		if(!head)
			return NULL;
		ListNode LEFT_HEAD(0);
		ListNode RIGHT_HEAD(0);
		ListNode *left_tail = &LEFT_HEAD;
		ListNode *right_tail = &RIGHT_HEAD;
		ListNode *cur = head;
		while(cur) {
			ListNode *tmp = cur;
			cur = tmp->next;
			if(tmp->val < x) {
				left_tail->next = tmp;
				tmp->next = NULL;
				left_tail = left_tail->next;
			} else {
				right_tail->next = tmp;
				tmp->next = NULL;
				right_tail = right_tail->next;
			}
		}
		left_tail->next = RIGHT_HEAD.next;
		return LEFT_HEAD.next;
    }
};
