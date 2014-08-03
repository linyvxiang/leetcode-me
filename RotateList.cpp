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
        if(!head || !head->next || !k)
            return head;
            
        int len = 1, cur_pos;
        ListNode *end = head, *new_end = head, *new_head;
        while(end->next) {
            len++;
            end = end->next;
        }
        k = k % len;
        if(!k)
            return head;
        for(cur_pos = 0; cur_pos < len - k - 1; cur_pos++)
            new_end = new_end->next;
            
        new_head = new_end->next;
        new_end->next = NULL;
        end->next = head;
        return new_head;
    }
};
