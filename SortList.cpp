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
    ListNode *sortList(ListNode *head) {
		if(!head)
			return head;
		int len = get_len(head);
		return merge_sort(head, len);
    }
private:

	int get_len(ListNode *head)
	{
		ListNode *tmp = head;
		int len = 0;
		while(tmp) {
			len++;
			tmp = tmp->next;
		}
		return len;
	}

	ListNode *find_nth(ListNode *head, int pos)
	{
		ListNode HEAD(0);
		HEAD.next = head;
		ListNode *cur = &HEAD;
		while(pos--) {
			cur = cur->next;
		}
		return cur;
	}

	ListNode *do_merge(ListNode *l, ListNode *r) 
	{
		ListNode HEAD(0);
		HEAD.next = NULL;
		ListNode *tail = &HEAD;
		while(l && r) {
			ListNode *tmp;
			if(l->val  < r->val) {
				tmp = l;
				l = l->next;
			} else {
				tmp = r;
				r = r->next;
			}
			tail->next = tmp;
			tail = tmp;
			tail->next = NULL;
		}
		tail->next = l ? l : r;

		return HEAD.next;
	}


	ListNode *merge_sort(ListNode *head, int len)
	{
		if(len == 1) {
			head->next = NULL;
			return head;
		}
		ListNode *left_tail = find_nth(head, len / 2);
		ListNode *right_head = left_tail->next;
		left_tail->next = NULL;
		ListNode *l = merge_sort(head, len / 2);
		ListNode *r = merge_sort(right_head, len - len / 2);
		return do_merge(l, r);
	}
};
