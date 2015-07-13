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
        if (left) {
            tail->next = left;
        } else {
            tail->next = right;
        }
        return HEAD.next;
    }
    ListNode* merge_sort(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode HEAD(0);
        HEAD.next = head;
        ListNode* slow = &HEAD;
        ListNode* fast = &HEAD;
        while (fast) {
            if (fast->next) {
                fast = fast->next->next;
                slow = slow->next;
            } else {
                break;
            }
        }
        ListNode* right = slow->next;
        slow->next = NULL;
        ListNode* new_left = merge_sort(head);
        ListNode* new_right = merge_sort(right);
        return merge_list(new_left, new_right);
    }
};
