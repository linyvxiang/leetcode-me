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
        return merge_lists(lists, 0, lists.size() - 1);
    }
private:
    ListNode *merge_lists(vector<ListNode *> &lists, int start_pos, int end_pos)
    {
        if(start_pos > end_pos)
            return NULL;
        if(start_pos == end_pos)
            return lists[start_pos];
        int mid = (start_pos + end_pos) >> 1;
        ListNode *left_list = merge_lists(lists, start_pos, mid);
        ListNode *right_list = merge_lists(lists, mid + 1, end_pos);
        return do_merge(left_list, right_list); 
    }
    ListNode *do_merge(ListNode *left, ListNode *right)
    {
        ListNode HEAD(0), *tail = &HEAD;
        while(left && right){
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
