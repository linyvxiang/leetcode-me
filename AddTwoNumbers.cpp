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
        ListNode *head1 = (ListNode *)malloc(sizeof(ListNode));
        ListNode *head2 = (ListNode *)malloc(sizeof(ListNode));
        head1->next = l1;
        head2->next = l2;
    
        ListNode *point1 = l1;
        ListNode *point2 = l2;
        ListNode *res = (ListNode *)malloc(sizeof(ListNode));
        res->next = NULL;
        ListNode *tmp = NULL;
        ListNode * cur = res;
        int flag = 0;
        while(point1 && point2) {
            tmp = (ListNode*)malloc(sizeof(ListNode));
            tmp->next = NULL;
            tmp->val = (point1->val + point2->val + flag) % 10;
            flag = (point1->val + point2->val + flag) / 10;
            cur->next = tmp;
            cur = cur->next;
            point1 = point1->next;
            point2 = point2->next;
        }
        while(point1) {
            tmp = (ListNode *)malloc(sizeof(ListNode));
            tmp->next = NULL;
            tmp->val = (point1->val + flag) % 10;
            flag = (point1->val + flag) / 10;
            cur->next = tmp;
            cur = cur->next;
            point1= point1->next;
        }
        while(point2) {
            tmp = (ListNode *)malloc(sizeof(ListNode));
            tmp->next = NULL;
            tmp->val = (point2->val + flag) % 10;
            flag = (point2->val + flag) / 10;
            cur->next = tmp;
            cur = cur->next;
            point2 = point2->next;
        }
        if(flag) {
            tmp = (ListNode *)malloc(sizeof(ListNode));
            tmp->next = NULL;
            tmp->val = flag;
            cur->next = tmp;
        }
        
        return res->next;
    }
};
