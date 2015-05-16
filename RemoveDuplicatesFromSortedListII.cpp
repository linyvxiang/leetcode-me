class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode HEAD(0);
        ListNode* tail = &HEAD;
        while (fast) {
            while (fast && fast->val == slow->val) {
                fast = fast->next;
            }
            if (fast == slow->next) {
                slow->next = tail->next;
                tail->next = slow;
                tail = tail->next;
            } else {
                ListNode* node_to_free = slow->next;
                while (node_to_free && node_to_free != fast) {
                    ListNode* next_node = node_to_free->next;
                    free(node_to_free);
                    node_to_free = next_node;
                }
            }
            slow = fast;
        }
        return HEAD.next;
    }
};
