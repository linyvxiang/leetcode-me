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
    ListNode* sortList(ListNode* head) {
        return merge_sort(head);
    }
private:
    ListNode* merge_list(ListNode* left, ListNode* right) {
        ListNode HEAD(0);
        ListNode* cur_tail = &HEAD;
        while (left && right) {
            if (left->val < right->val) {
                cur_tail->next = left;
                cur_tail = cur_tail->next;
                left = left->next;
            } else {
                cur_tail->next = right;
                cur_tail = cur_tail->next;
                right = right->next;
            }
        }
        if (left) {
            cur_tail->next = left;
        } else {
            cur_tail->next = right;
        }
        return HEAD.next;
    }
    ListNode* merge_sort(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* right = slow->next;
        slow->next = NULL;
        head = merge_sort(head);
        right = merge_sort(right);
        return merge_list(head, right);
    }
};
