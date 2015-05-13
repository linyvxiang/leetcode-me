class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode HEAD(0);
        HEAD.next = head;
        ListNode* left = &HEAD;
        ListNode* right = NULL;
        ListNode* cur = HEAD.next;
        int cur_pos = 0;
        while (cur) {
            cur_pos++;
            if (cur_pos == m - 1) {
                left = cur;
            }
            if (cur_pos == n) {
                right = cur->next;
                break;
            }
            cur = cur->next;
        }
        //reverse part between m and n
        ListNode* cur_reverse = left->next;
        left->next = NULL;
        cur->next = NULL;
        ListNode REVERSE_HEAD(0);
        ListNode* tail = NULL;
        while (cur_reverse) {
            ListNode* tmp = cur_reverse->next;
            if (REVERSE_HEAD.next == NULL) {
                tail = cur_reverse;
            }
            cur_reverse->next = REVERSE_HEAD.next;
            REVERSE_HEAD.next = cur_reverse;
            cur_reverse = tmp;
        }
        left->next = REVERSE_HEAD.next;
        tail->next = right;
        return HEAD.next;
    }
};
