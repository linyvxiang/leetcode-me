class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode HEAD(0);
        ListNode* tail = &HEAD;
        int cf = 0;
        while (l1 && l2) {
            ListNode* new_node = (ListNode*)malloc(sizeof(struct ListNode));
            new_node->next = tail->next;
            tail->next = new_node;
            tail = new_node;
            new_node->val = (l1->val + l2->val + cf) % 10;
            cf = (l1->val + l2->val + cf) / 10;
            l1 = l1->next;
            l2 = l2->next;
        }
        ListNode* l = l1 ? l1 : l2;
        tail->next = l;
        while (l) {
            int val = l->val + cf;
            l->val = val % 10;
            cf = val / 10;
            tail = l;
            l = l->next;
        }
        if (cf) {
            ListNode* new_node = (ListNode*)malloc(sizeof(struct ListNode));
            new_node->next = NULL;
            new_node->val = cf;
            tail->next = new_node;
        }
        return HEAD.next;
    }
};
