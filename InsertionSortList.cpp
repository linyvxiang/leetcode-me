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
    ListNode *insertionSortList(ListNode *head) {
        ListNode RES_HEAD(0), *cur = head;
        while(cur) {
            ListNode *tmp = cur->next, *pre = &RES_HEAD;
            cur->next = NULL;
            while(pre) {
                if(!pre->next) {
                    pre->next = cur;
                    break;
                } else if(pre->next->val > cur->val) {
                    cur->next = pre->next;
                    pre->next = cur;
                    break;
                } else {
                    pre = pre->next;
                }
            }
            cur = tmp;
        }
        return RES_HEAD.next;
    }
};
