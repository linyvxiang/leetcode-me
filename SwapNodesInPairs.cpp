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
    ListNode *swapPairs(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(!head)
            return NULL;
        ListNode *root =(ListNode *)malloc(sizeof(ListNode));
        root->next = head;
        ListNode *last = root, *back = NULL, *front = NULL, *tmp = NULL;
        while(last) {
            if(!last->next)
                break;
            back = last->next;
            if(!back->next)
                break;
            front = back->next;
            tmp = front;
            back->next = front->next;
            last->next = tmp;
            tmp->next = back;
            last = back;
        }
        return root->next;
    }
};
