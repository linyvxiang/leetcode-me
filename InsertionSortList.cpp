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
        ListNode HEAD(0);
        HEAD.next = head;
        if(!head || !head->next)
            return head;
        ListNode *pre = &HEAD;
        ListNode *cur = head->next;
        ListNode *cur_prev = head;
        while(cur) {
            ListNode *new_pos = HEAD.next;
            pre = &HEAD;
            while(new_pos != cur && new_pos->val < cur->val) {
                pre = new_pos;
                new_pos = new_pos->next;
            }
            // insert between pre and new_pos
            if(new_pos == cur) {
                cur_prev = cur;
                cur= cur->next;
                continue;
            }
            cur_prev->next = cur->next;
            cur->next = pre->next;
            pre->next = cur;
            cur = cur_prev->next;
        }
        return HEAD.next;
    }
};
