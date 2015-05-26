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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return do_merge(lists, 0, lists.size() - 1);
    }
private:
    ListNode* do_merge(vector<ListNode*>& lists, int start, int end) {
        if (start > end) {
            return NULL;
        }
        if (start == end) {
            return lists[start];
        }
        int mid = (start + end) / 2;
        ListNode* left = do_merge(lists, start, mid);
        ListNode* right = do_merge(lists, mid + 1, end);
        ListNode HEAD(0);
        ListNode* tail = &HEAD;
        while (left && right) {
            if (left->val < right->val) {
                tail->next = left;
                left = left->next;
            } else {
                tail->next = right;
                right = right->next;
            }
            tail = tail->next;
        }
        tail->next = left ? left : right;
        return HEAD.next;
    }
};
