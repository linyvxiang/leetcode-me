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
    void reorderList(ListNode *head) {
        ListNode *reverse_start = find_mid_node(head);
        reverse_start = reverse_list(reverse_start);
        ListNode HEAD(0), *cur = head;
        HEAD.next = reverse_start;
        while(HEAD.next) {
            ListNode *tmp = HEAD.next;
            HEAD.next = tmp->next;
            tmp->next = cur->next;
            cur->next = tmp;
            cur = tmp->next;
        }
    }
private:
    ListNode *find_mid_node(ListNode *start)
    {
        int len = 0, pos = 0;
        ListNode *cur = start;
        while(cur) {
            len++;
            cur = cur->next;
        }
        pos = (len + 1) >> 1;
        cur = start;
        ListNode *pre = NULL;
        while(pos--) {
            pre = cur;
            cur = cur->next;
        }
        if(pre)
            pre->next = NULL;
        return cur;
    }
    ListNode *reverse_list(ListNode *head)
    {
        ListNode HEAD(0);
        HEAD.next = NULL;
        ListNode *cur = head;
        while(cur) {
            ListNode *tmp = cur->next;
            cur->next = HEAD.next;
            HEAD.next = cur;
            cur = tmp;
        }
        return HEAD.next;
    }
};
