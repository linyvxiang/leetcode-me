class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast) { // cycle
                ListNode* new_slow = head;
                while (new_slow != slow) {
                    new_slow = new_slow->next;
                    slow = slow->next;
                }
                return new_slow;
            }
        }
        return NULL;
    }
};
