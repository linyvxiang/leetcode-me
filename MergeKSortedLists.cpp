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
            if(lists.empty())
                return NULL;
            return merge_lists(lists, 0, lists.size() - 1);
        }
    private:
        ListNode *merge_lists(vector<ListNode *> &lists,
                                int start, int end)
        {
            if(start > end)
                return NULL;
            if(start == end)
                return lists[start];
            ListNode *l = merge_lists(lists, start, 
                                        start + (end - start) / 2);
            ListNode *r = merge_lists(lists,
                             start + (end - start) / 2 + 1,
                             end);
            return do_merge(l, r);
        }
        ListNode *do_merge(ListNode *l, ListNode *r)
        {
            ListNode HEAD(0);
            ListNode *tail = &HEAD;
            while(l && r) {
                if(l->val < r->val) {
                    tail->next = l;
                    l = l->next;
                } else {
                    tail->next = r;
                    r = r->next;
                }
                tail = tail->next;
            }
            tail->next = l ? l : r;
            return HEAD.next;
        }
};
