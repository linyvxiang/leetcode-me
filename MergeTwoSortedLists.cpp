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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode HEAD(0);
        ListNode* tail = &HEAD;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                ListNode* tmp = l1->next;
                l1->next = tail->next;
                tail->next = l1;
                tail = l1;
                l1 = tmp;
            } else {
                ListNode* tmp = l2->next;
                l2->next = tail->next;
                tail->next = l2;
                tail = l2;
                l2 = tmp;
            }
        }
        if (l1) {
            tail->next = l1;
        } else {
            tail->next = l2;
        }
        return HEAD.next;
    }
};
