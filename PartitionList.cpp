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
    ListNode* insert(ListNode *target, ListNode &head, ListNode *tail)
    {
        if(head.next == NULL) {//first insert 
            head.next = target;
            tail = target;
        } else {
            tail->next = target;
            tail = target;
        }
        tail->next = NULL;    
    }
    ListNode *partition(ListNode *head, int x) {
        ListNode left_head(0), *left_tail, right_head(0), *right_tail;
        ListNode *cur_pos = head;
        if(!head)
            return head;
        while(cur_pos) {
            ListNode *tmp = cur_pos->next;
            if(cur_pos->val < x)  //insert to the left list
                left_tail = insert(cur_pos, left_head, left_tail);
            else
                right_tail = insert(cur_pos, right_head, right_tail);
            cur_pos = tmp;
        }
        if(!left_head.next)
            return right_head.next;
        left_tail->next = right_head.next;
        return left_head.next;
    }
};
