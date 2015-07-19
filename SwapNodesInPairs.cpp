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
        ListNode* first = head;
        ListNode* second = head;
        while (first) {
            second = first->next;
            if (!second) {
                first->next = tail->next;
                tail->next = first;
                break;
            }
            ListNode* tmp = second->next;
            first->next = tail->next;
            tail->next = second;
            second->next = first;
            tail = first;
            first = tmp;
        }
        return HEAD.next;
    }
};
