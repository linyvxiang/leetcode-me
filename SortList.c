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
  ListNode* merge(ListNode* h1, ListNode* h2) {
        ListNode* dump = new ListNode(0);
        ListNode* p = dump;
        while(h1!=NULL && h2!=NULL) {
            if(h1->val<h2->val){
                p->next = h1;
                h1 = h1->next;
            } else {
                p->next = h2;
                h2 = h2->next;
            }
            p = p->next;
        }
        
        if(h1!=NULL) p->next = h1;
        else p->next = h2;
        ListNode* head = dump->next;
        delete dump;
        return head;
  }
    ListNode *do_sort(ListNode *head)
    {
        if(!head || !head->next)
            return head;
        ListNode *right_start = head, *pre = head, *right_end = head;
        while(right_end && right_end->next) {
            right_end = right_end->next->next;
            pre = right_start;
            right_start = right_start->next;
        }
        pre->next = NULL;
        ListNode *l = do_sort(head);
        ListNode *r = do_sort(right_start);
        merge(l, r);
    }
    ListNode *sortList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        //merge sort
        return do_sort(head);
    }
};
