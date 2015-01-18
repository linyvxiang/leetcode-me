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
        ListNode *fast = &HEAD, *slow = &HEAD;
        n++;
        while(n--)
            fast = fast->next;
        while(fast) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode *tmp = slow->next;
        slow->next = tmp->next;
        free(tmp);
        return HEAD.next;
    }
};
