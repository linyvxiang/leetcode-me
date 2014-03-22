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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *head = (ListNode *)malloc(sizeof(ListNode));
        head->next = NULL;
        ListNode *cur = head, *p1 = l1, *p2 = l2;
        int flag = 0;
        while(p1 && p2) {
            ListNode *tmp = (ListNode *)malloc(sizeof(ListNode));
            tmp->next = NULL;
            tmp->val = (p1->val + p2->val + flag) % 10;
            flag = (p1->val + p2->val + flag) / 10;
            cur->next = tmp;
            cur = tmp;
            p1 = p1->next;
            p2 = p2->next;
        }
        ListNode *remain;
        if(p1)
            remain = p1;
        else
            remain = p2;
        while(remain) {
            ListNode *tmp = (ListNode *)malloc(sizeof(ListNode));
            tmp->next = NULL;
            tmp->val = (remain->val + flag) % 10;
            flag = (remain->val + flag) / 10;
            cur->next = tmp;
            cur = tmp;
            remain = remain->next;
        }
        if(flag) {
            ListNode *tmp = (ListNode*)malloc(sizeof(ListNode));
            tmp->val = flag;
            tmp->next = NULL;
            cur->next = tmp;
        }
        return head->next;
    }
};
