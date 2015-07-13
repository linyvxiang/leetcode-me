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
        while (head) {
            ListNode* cur_node = head;
            head = head->next;
            insert_node(&HEAD, cur_node);
        }
        return HEAD.next;
    }
private:
    void insert_node(ListNode* head, ListNode* new_node) {
        ListNode* prev = head;
        ListNode* cur = head->next;
        while (cur && cur->val < new_node->val) {
            cur = cur->next;
            prev = prev->next;
        }
        new_node->next = prev->next;
        prev->next = new_node;
    }
};
