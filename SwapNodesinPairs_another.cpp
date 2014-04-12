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
        if(!head)
            return head;
        ListNode HEAD(0);
        HEAD.next = head;
        ListNode *prev = &HEAD, *cur = head, *tmp;
        ListNode *fast, *slow;
        while(cur) {
            if(!cur->next)
                break;
            fast = cur->next;
            slow = cur;
            tmp = fast->next;
            fast->next = slow;
            slow->next = tmp;
            prev->next = fast;
            prev = slow;
            cur = tmp;
        }
        return HEAD.next;
    }
};
