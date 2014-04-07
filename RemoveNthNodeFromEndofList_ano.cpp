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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode HEAD(0);
        HEAD.next = head;
        ListNode *slow = &HEAD, *fast = head;
        while(n && fast) {
            fast = fast->next;
            n--;
        }
        if(!fast)
            return head->next;
        while(fast) {
            fast = fast->next;
            slow = slow->next;
        }
        if(slow->next)
        slow->next = slow->next->next;
        return head;
    }
};
