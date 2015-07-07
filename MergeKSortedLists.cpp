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
    struct ListCmp {
        bool operator()(ListNode* l1, ListNode* l2) const {
            return l1->val > l2->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, ListCmp> heap;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i]) {
                heap.push(lists[i]);
            }
        }
        ListNode HEAD(0);
        ListNode* tail = &HEAD;
        while (!heap.empty()) {
            tail->next = heap.top();
            heap.pop();
            tail = tail->next;
            if (tail->next) {
                heap.push(tail->next);
            }
        }
        return HEAD.next;
    }
};
