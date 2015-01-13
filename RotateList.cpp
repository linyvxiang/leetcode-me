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
        ListNode *rotateRight(ListNode *head, int k) {
            if(!head)
                return head;
            ListNode HEAD(0);
            HEAD.next = head;
            ListNode *cur_node = head, *next_node, *tail = &HEAD;
            int len = 0;
            while(cur_node) {
                len++;
                cur_node = cur_node->next;
                tail = tail->next;
            }
            k %= len;
            if(k == 0)
                return HEAD.next;
            int p_len = len - k;
            cur_node = &HEAD;
            while(p_len--)
                cur_node = cur_node->next;
            next_node = cur_node->next;
            cur_node->next = NULL;
            tail->next = HEAD.next;
            HEAD.next = next_node;
            return HEAD.next;
        }
};
