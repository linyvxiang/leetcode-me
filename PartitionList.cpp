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
    ListNode* partition(ListNode* head, int x) {
        ListNode LEFT(0);
        ListNode* left_tail = &LEFT;
        ListNode RIGHT(0);
        ListNode* right_tail = &RIGHT;
        ListNode* cur = head;
        while (cur) {
            ListNode* tmp = cur->next;
            if (cur->val < x) {
                cur->next = left_tail->next;
                left_tail->next = cur;
                left_tail = cur;
            } else {
                cur->next = right_tail->next;
                right_tail->next = cur;
                right_tail = cur;
            }
            cur = tmp;
        }
        left_tail->next = RIGHT.next;
        return LEFT.next;
    }
};