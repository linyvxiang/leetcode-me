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
    void reorderList(ListNode *head) {
		if(!head || !head->next)
			return ;

		int len = get_len(head);
		ListNode *left_tail = get_pos_node(head, len / 2);
		ListNode *right_head = left_tail->next;
		left_tail->next = NULL;
		right_head = reverse_list(right_head);
		ListNode *left_head = head;
		while(left_head) {
			ListNode *tmp = right_head;
			right_head = right_head->next;
			tmp->next = left_head->next;
			left_head->next = tmp;
			if(tmp->next) {
		    	left_head = tmp->next;
			} else {
		        tmp->next = right_head;
		        break;
		    }
		}
    }
private:
	int get_len(ListNode *head)
	{
		int len = 0;
		while(head) {
			len++;
			head = head->next;
		}
		
		return len;
	}
	ListNode *get_pos_node(ListNode *head, int pos)
	{
		int cur_pos = 1;
		while(cur_pos < pos) {
			cur_pos++;
			head = head->next;
		}
		return head;
		
	}
	ListNode* reverse_list(ListNode *head)
	{
		ListNode HEAD(0);
		while(head) {
			ListNode *tmp = head;
			head = head->next;
			tmp->next = HEAD.next;
			HEAD.next = tmp;
		}
		return HEAD.next;
	}
};
