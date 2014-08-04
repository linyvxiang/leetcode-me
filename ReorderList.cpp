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
    void reorderList(ListNode *head) {
        if(!head || !head->next)
            return ;
        int len = get_len(head);
        ListNode *front_end = find_mid(head, len / 2 + 1);
        ListNode *reverse_head = front_end->next;
        front_end->next = NULL;
        reverse_head = reverse_list(reverse_head);
        insert_list(head, reverse_head);
    }
private:
    int get_len(ListNode *head)
    {
        int l = 0;
        ListNode *cur = head;
        while(cur) {
            l++;
            cur = cur->next;
        }
        return l;
    }
    ListNode *find_mid(ListNode *head, int target_pos)
    {
        int cur_pos = 0;
        ListNode HEAD(0);
        HEAD.next = head;
        ListNode *cur = &HEAD;
        while(cur_pos < target_pos) {
            cur_pos++;
            cur = cur->next;
        }
        return cur;
    }
    ListNode *reverse_list(ListNode *head)
    {
        ListNode HEAD(0);
        HEAD.next = NULL;
        ListNode *cur = head;
        while(cur) {
            ListNode *tmp = cur->next;
            cur->next = HEAD.next;
            HEAD.next = cur;
            cur = tmp;
        }
        return HEAD.next;
    }
    void insert_list(ListNode *left, ListNode *right)
    {
        ListNode *left_cur = left, *right_cur = right;
        while(right_cur) {
            ListNode *tmp = right_cur->next;
            right_cur->next = left_cur->next;
            left_cur->next = right_cur;
            left_cur = left_cur->next->next;
            right_cur = tmp;
        }
    }
};
