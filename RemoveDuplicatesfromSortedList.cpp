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
        ListNode *result = head, *result_tail = head, *cur_pos = head->next;
        while(cur_pos) {
            while(cur_pos && cur_pos->val == result_tail->val) {
                cur_pos = cur_pos->next;
            }// ok, now cur_pos->val != result_vail->val, so a new elemnet is to be added
            if(!cur_pos)
                break;
            result_tail->next = cur_pos;
            result_tail = cur_pos;
            cur_pos = cur_pos->next;
        }
        result_tail->next = NULL;
        return result;
    }
};
