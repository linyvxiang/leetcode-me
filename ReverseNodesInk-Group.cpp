class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head) {
            return NULL;
        }
        ListNode HEAD(0);
        ListNode* cur = head;
        ListNode* tail = &HEAD;
        while (cur) {
            ListNode* k_tail = select_k_nodes(cur, k);
            if (!k_tail) {
                tail->next = cur;
                return HEAD.next;
            }
            ListNode* next_cur = k_tail->next;
            k_tail->next = NULL;
            reverse_list(cur);
            tail->next = k_tail;
            tail = cur;
            tail->next = NULL;
            cur = next_cur;
        }
        return HEAD.next;
    }
private:
    ListNode* select_k_nodes(ListNode* head, int k) {
        ListNode* tail = head;
        for (int i = 1; i < k && tail; i++) {
            tail = tail->next;
        }
        return tail;
    }
    ListNode* reverse_list(ListNode* head) {
        ListNode HEAD(0);
        while(head) {
            ListNode* tmp = head->next;
            head->next = HEAD.next;
            HEAD.next = head;
            head = tmp;
        }
        return HEAD.next;
    }
};
