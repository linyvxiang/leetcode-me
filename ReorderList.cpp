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
    void reorderList(ListNode* head) {
        if (!head || !head->next) {
            return;
        }
        ListNode* fast = head->next;
        ListNode* slow = head;
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
        right = reverse_list(right);
        ListNode* left = head;
        while (right) {
            ListNode* tmp = right->next;
            right->next = left->next;
            left->next = right;
            left = right->next;
            right = tmp;
        }
    }
private:
    ListNode* reverse_list(ListNode* head) {
        ListNode HEAD(0);
        while (head) {
            ListNode* tmp = head->next;
            head->next = HEAD.next;
            HEAD.next = head;
            head = tmp;
        }
        return HEAD.next;
    }
};