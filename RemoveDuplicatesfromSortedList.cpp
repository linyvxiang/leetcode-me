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
        ListNode *cur = head;
        while(cur) {
            ListNode *front = cur->next;
            while(front && front->val == cur->val) {
                ListNode *tmp = front->next;
                free(front);
                cur->next = tmp;
                front = tmp;
            }
            cur = cur->next;
        }
        return head;
    }
};
