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
        ListNode *deleteDuplicates(ListNode *head) {
            ListNode HEAD(0);
            ListNode *tail = &HEAD;
            ListNode *cur_node = head, *next_node;
            while(cur_node) {
                next_node = cur_node;
                while(next_node && cur_node->val == next_node->val)
                    next_node = next_node->next;
                tail->next = cur_node;
                tail = tail->next;
                cur_node = next_node;
                tail->next = cur_node;
            }

            return HEAD.next;
        }
};
