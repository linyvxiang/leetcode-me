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
    ListNode *deleteDuplicates(ListNode *head) 
    {
        ListNode HEAD(0);
        HEAD.next = head;
        ListNode *pre = &HEAD, *cur = head;
        while(cur) {
            ListNode *front = cur;
            while(front && front->val == cur->val)
                front = front->next;
            if(front == cur->next) {
                pre = cur;
                cur = cur->next;
            } else {
                pre->next = front;
                while(cur && cur->next != front) {
                    ListNode *tmp = cur->next;
                    free(cur);
                    cur = tmp;
                }
                cur = front;
            }
        }
        return HEAD.next;
    }
};
