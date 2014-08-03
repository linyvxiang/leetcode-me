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
    ListNode *swapPairs(ListNode *head) {
        ListNode HEAD(0);
        HEAD.next = head;
        ListNode *pre = &HEAD, *first, *second, *end;
        while(pre && pre->next && pre->next->next) {
            first = pre->next;
            second = first->next;
            end = second->next;

            pre->next = second;
            first->next = end;
            second->next = first;
            pre = first;
        }
        return HEAD.next;
    }
};
