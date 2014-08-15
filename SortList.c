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
    ListNode *sortList(ListNode *head) {
        int len = 0;
        ListNode *p = head;
        while(p) {
            len++;
            p = p->next;
        }
        return merge_sort_list(head, len);
    }
private:
    ListNode *merge_sort_list(ListNode *head, int len)
    {
        if(len == 0)
            return NULL;
        if(len == 1)
            return head;
        int l = len / 2;
        ListNode HEAD(0), *cur = &HEAD;
        HEAD.next = head;
        while(l--)
            cur = cur->next;
        ListNode *right = cur->next;
        cur->next = NULL;
        ListNode *left = merge_sort_list(HEAD.next, len / 2);
        right = merge_sort_list(right, len - (len / 2));
        return do_merge(left, right);
    }
    ListNode *do_merge(ListNode *left, ListNode *right)
    {
        ListNode HEAD(0), *tail = &HEAD;
        while(left && right) {
            if(left->val < right->val) {
                tail->next = left;
                left = left->next;
            } else {
                tail->next = right;
                right = right->next;
            }
            tail = tail->next;
            tail->next = NULL;
        }
        tail->next = left ? left : right;
        return HEAD.next;
    }
};
