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
        ListNode RIGHT(0);
        ListNode* left_tail = &LEFT;
        ListNode* right_tail = &RIGHT;
        ListNode* cur_node = head;
        while (cur_node) {
            ListNode* tmp = cur_node->next;
            if (cur_node->val < x) {
                left_tail->next = cur_node;
                left_tail = cur_node;
            } else {
                right_tail->next = cur_node;
                right_tail = cur_node;
                right_tail->next = NULL;
            }
            cur_node = tmp;
        }
        left_tail->next = RIGHT.next;
        return LEFT.next;
    }
};
