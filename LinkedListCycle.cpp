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
    bool hasCycle(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
       ListNode *fast = head;
       ListNode *slow = head;
       if(!head)
        return false;
       while(fast) {
           if(!fast->next)
            break;
           fast = fast->next->next;
           slow = slow->next;
           if(fast == slow)
            break;
       }
       return !(fast == NULL || fast->next == NULL);
    }
};
