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
        int c = 0;
        ListNode HEAD(0);
        ListNode *tail = &HEAD;
        while(l1 && l2) {
            ListNode *tmp = l1->next;
            int t = (l1->val + l2->val + c);
            l1->val = t % 10;
            c = t / 10;
            l1->next = NULL;
            tail->next = l1;
            tail = l1;
            l1 = tmp;
            l2 = l2->next;
        }
        ListNode *more = l1 ? l1 : l2;
        tail->next = more;
        while(more) {
            int t = (more->val + c);
            more->val = t % 10;
            c = t / 10;
            tail = more;
            more = more->next;
        }
        if(c) {
            tail->next = (ListNode *)malloc(sizeof(struct ListNode));
            tail->next->next = NULL;
            tail->next->val = 1;
        }
        return HEAD.next;
    }
};
