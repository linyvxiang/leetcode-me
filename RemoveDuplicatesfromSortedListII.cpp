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
    ListNode *insert(ListNode *target, ListNode &head, ListNode *tail)
    {
        if(!head.next) {
            head.next = target;
            tail = target;
        } else {
            tail->next = target;
            tail = target;
        }
        tail->next = NULL;
        return tail;
    }
    ListNode *deleteDuplicates(ListNode *head) {
        if(!head || !head->next)
            return head;
        ListNode result_head(0), *result_tail, *pre = head, *cur = head->next;
        while(pre) {
            while(cur && cur->val == pre->val)
                cur = cur->next;
            if(cur == pre->next) { //we didn't move
                result_tail = insert(pre, result_head, result_tail);
                pre = cur;
                if(cur)
                    cur = cur->next;
            } else {
                pre = cur;
                if(cur)
                    cur = cur->next;
            }
        }

        return result_head.next;
    }
};
