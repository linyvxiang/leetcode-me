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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) {
            return NULL;
        }
        ListNode HEAD(0);
        HEAD.next = head;
        ListNode* fast = &HEAD;
        ListNode* slow = &HEAD;
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* nth_node = slow->next;
        slow->next = nth_node->next;
        free(nth_node);
        return HEAD.next;
    }

};