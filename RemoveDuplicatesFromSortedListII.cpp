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
            if(!head)
                return head;
            ListNode HEAD(0);
            ListNode *cur_node = head, *tail = &HEAD;
            while(cur_node) {
                ListNode *next_node = cur_node->next;
                if(!next_node) {
                    tail->next = cur_node;
                    tail = tail->next;
                    tail->next = NULL;
                    break;
                }

                while(next_node && next_node->val == cur_node->val)
                    next_node = next_node->next;
                if(!next_node)
                    break;
                if(next_node == cur_node->next) {
                    tail->next = cur_node;
                    tail = tail->next;
                    cur_node = next_node;
                } else {
                    while(cur_node != next_node) {
                        ListNode *tmp = cur_node->next;
                        free(cur_node);
                        cur_node = tmp;
                    }
                }
            }
            tail->next = NULL;
            return HEAD.next;
        }
};
