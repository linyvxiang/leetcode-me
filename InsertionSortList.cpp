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
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode HEAD(0);
        ListNode* cur_node = head;
        while (cur_node) {
            cur_node = insert(HEAD, cur_node);
        }
        return HEAD.next;
    }
private:
    ListNode* insert(ListNode& HEAD, ListNode* cur_node) {
        ListNode* next_node = cur_node->next;
        ListNode* prev = &HEAD;
        ListNode* cur = HEAD.next;
        while (cur && cur->val < cur_node->val) {
            prev = cur;
            cur = cur->next;
        }
        cur_node->next = prev->next;
        prev->next = cur_node;
        return next_node;
    }
};
