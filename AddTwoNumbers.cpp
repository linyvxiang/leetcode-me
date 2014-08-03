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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *res_head = NULL, *res_end;
        int c = 0;
        while(l1 && l2) {
            if(!res_head) {
                res_head = (ListNode *)malloc(sizeof(struct ListNode));
                res_head->next = NULL;
                res_head->val = (l1->val + l2->val + c) % 10;
                c = (l1->val + l2->val + c) / 10;
                res_end = res_head;
            } else {
                res_end->next = (ListNode *)malloc(sizeof(struct ListNode));
                res_end = res_end->next;
                res_end->next = NULL;
                res_end->val = (l1->val + l2->val + c) % 10;
                c = (l1->val + l2->val + c) / 10;
            }
            l1 = l1->next;
            l2 = l2->next;
        }

        ListNode *l;
        l = l1 ? l1 : l2;
        while(l) {
            res_end->next = (ListNode *)malloc(sizeof(struct ListNode));
            res_end = res_end->next;
            res_end->next = NULL;
            res_end->val = (l->val + c) % 10;
            c = (l->val + c) / 10;
            l = l->next;
        }
        if(c) {
              res_end->next = (ListNode *)malloc(sizeof(struct ListNode));
               res_end->next->val = 1;
               res_end->next->next = NULL;
        }

        return res_head;
    }
};
