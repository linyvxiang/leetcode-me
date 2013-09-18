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
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *front = head->next;
        ListNode *bak = head;
        while(n-- && front) {
            front = front->next;
        }
        if(!front) {
            if(!bak->next) {
                free(bak);
                return NULL;
            }
            if(bak == head && !n) {
                ListNode *ans = head->next;
                free(head);
                return ans;
            }
            free(bak->next);
            bak->next = bak->next->next;
            return head;
        }
        while(front) {
            front = front->next;
            bak = bak->next;
        }
        if(bak->next) {
           ListNode *del = bak->next;
           bak->next = del->next;
           free(del);
        }
        return head;
    }
};
