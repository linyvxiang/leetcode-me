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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode HEAD(0);
        HEAD.next = NULL;
        ListNode *cur_final = &HEAD, *cur_pos_l1 = l1, *cur_pos_l2 = l2;
        while(l1 && l2) {
            if(l1->val < l2->val) {//move l1 to the right pos
                cur_final->next = l1;
                l1 = l1->next;
            } else {
                cur_final->next = l2;
                l2 = l2->next;
            }
            cur_final = cur_final->next;
            cur_final->next = NULL;
        }
        if(l1) {
            while(l1) {
                cur_final->next = l1;
                cur_final = cur_final->next;
                l1 = l1->next;
            }
        } else {
            while(l2) {
                cur_final->next = l2;
                cur_final = cur_final->next;
                l2 = l2->next;
            }
        }
        cur_final->next = NULL;
        return HEAD.next;
    }
};
