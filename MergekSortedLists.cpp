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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        return do_merge_k_lists(0, lists.size() - 1, lists);
    }
private:
    ListNode *merge_two_lists(ListNode *l1, ListNode *l2)
    {
        ListNode HEAD(0);
        ListNode *cur = &HEAD;
        while(l1 && l2) {
            if(l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        ListNode *p = l1 ? l1 : l2;
        cur->next = p;
        return HEAD.next;
    }
    ListNode *do_merge_k_lists(int start, int end, vector<ListNode *> &lists)
    {
        if(start > end)
            return NULL;
        if(start == end)
            return lists[start];
        int mid = (start + end) >> 1;
        ListNode *l1 = do_merge_k_lists(start, mid, lists);
        ListNode *l2 = do_merge_k_lists(mid + 1, end, lists);
        return merge_two_lists(l1, l2);
    }
};
