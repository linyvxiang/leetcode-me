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
    ListNode* swapPairs(ListNode* head) {
        ListNode HEAD(0);
        ListNode* tail = &HEAD;
        ListNode* fast = head;
        ListNode* slow = NULL;
        while (fast) {
            slow = fast;
            fast = fast->next;
            if (!fast) {//last one
                tail->next = slow;
                tail = slow;
                break;
            }
            ListNode* tmp = fast->next;
            fast->next = slow;
            tail->next = fast;
            tail = slow;
            fast = tmp;
        }
        tail->next = NULL;
        return HEAD.next;
    }
};
