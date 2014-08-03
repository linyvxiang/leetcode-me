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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if(!head)
            return head;
        ListNode HEAD(0);
        HEAD.next = head;
        ListNode *fast = &HEAD, *slow = &HEAD, *d;
        
        while(n--) 
            fast = fast->next;
            
        while(fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        
        d = slow->next;
        slow->next = d->next;
        free(d);
        return HEAD.next;
    }
};
