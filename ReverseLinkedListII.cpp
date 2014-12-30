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
        ListNode *reverseBetween(ListNode *head, int m, int n) {
            if(!head)
                return NULL;
            ListNode HEAD(0);
            HEAD.next = head;
            ListNode *head_pointer = find_nth_pointer(&HEAD, m);
            ListNode *tail_pointer = find_nth_pointer(&HEAD, n + 1);

            ListNode *reverse_head = head_pointer->next;
            ListNode *reverse_tail = tail_pointer;
            ListNode *new_tail = tail_pointer->next;
            reverse(reverse_head, reverse_tail);
            head_pointer->next = reverse_head;
            reverse_tail->next = new_tail;
            return HEAD.next;;
        }
    private:
        ListNode *find_nth_pointer(ListNode* head, int pos)
        {
            ListNode *cur_p = head;
            int cur_pos = 1;
            while(cur_pos != pos) {
                cur_p = cur_p->next;
                cur_pos++;
            }

            return cur_p;
        }
        void reverse(ListNode* &head, ListNode* &tail)
        {
            ListNode HEAD(0);
            ListNode *cur_pos = head;
            ListNode *_tail = head;
            while(cur_pos != tail) {
                ListNode *tmp = cur_pos->next;
                cur_pos->next = HEAD.next;
                HEAD.next = cur_pos;
                cur_pos = tmp;
            }
            tail->next = HEAD.next;
            HEAD.next = tail;
            head = tail;
            tail = _tail; 
        }
};
