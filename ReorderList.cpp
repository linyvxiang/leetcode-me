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
        ListNode* slow = head;
        ListNode* fast = head->next;
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
            ListNode* tmp = right;
            right = right->next;
            tmp->next = left->next;
            left->next = tmp;
            left = tmp->next;
        }
    }
private:
    ListNode* reverse_list(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode HEAD(0);
        while (head) {
            ListNode* tmp = head;
            head = head->next;
            tmp->next = HEAD.next;
            HEAD.next = tmp;
        }
        return HEAD.next;
    }
};
