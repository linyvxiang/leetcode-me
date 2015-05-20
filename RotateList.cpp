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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) {
            return NULL;
        }
        ListNode HEAD(0);
        HEAD.next = head;
        ListNode* fast = head;
        ListNode* slow = &HEAD;
        int len = 0;
        while (fast) {
            len++;
            fast = fast->next;
        }
        k %= len;
        if (k == 0) {
            return head;
        }
        fast = &HEAD;
        for (int i = 0; i < k; i++) {
            fast = fast->next;
        }
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        fast->next = HEAD.next;
        fast = slow->next;
        slow->next = NULL;
        HEAD.next = fast;
        return HEAD.next;
    }
};
