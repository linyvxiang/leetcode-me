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
 ListNode *reverseBetween(ListNode *head, int m, int n) {
		ListNode *HEAD = (ListNode *)malloc(sizeof(struct ListNode));
		HEAD->next = head;
        ListNode *pre = HEAD;
        if(!head || m == n)
            return head;
        int cur_pos = 1;
        while(cur_pos < m) {
            pre = pre->next;
            cur_pos++;
        }//now the pre->next is at the m pos
        ListNode *pos_m = pre->next, *pos_n = pre->next;
        while(cur_pos < n) {
            pos_n = pos_n->next;
            cur_pos++;
        }//now the pos_n->next is the tail
        while(pos_m != pos_n) {
            ListNode *tmp = pos_m->next;
            pos_m->next = pos_n->next;
            pos_n->next = pos_m;
            pos_m = tmp;
        }
        pre->next = pos_n;
        return HEAD->next;
    }
    
};
