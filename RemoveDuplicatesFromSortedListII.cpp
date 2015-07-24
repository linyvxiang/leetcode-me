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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode HEAD(0);
        ListNode* tail = &HEAD;
        ListNode* cur_node = head;
        while (cur_node) {
            ListNode* next_node = cur_node;
            while (next_node && next_node->val == cur_node->val) {
                next_node = next_node->next;
            }
            if (next_node == cur_node->next) {
                tail->next = cur_node;
                tail = cur_node;
                tail->next = NULL;
            } else {
                ListNode* tmp = cur_node;
                while (tmp != next_node) {
                    ListNode* t = tmp->next;
                    free(tmp);
                    tmp = t;
                }
            }
            cur_node = next_node;
        }
        return HEAD.next;
    }
};
