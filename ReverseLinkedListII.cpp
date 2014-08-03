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
            return head;
        ListNode HEAD(0);
        HEAD.next = head;
        ListNode *front = find_pos(&HEAD, m - 1);
        ListNode *reverse_end = find_pos(&HEAD, n);
        ListNode *end = reverse_end->next;
        reverse(front->next, reverse_end);
        front->next->next = end;
        front->next = reverse_end;
        return HEAD.next;
    }

private:
    ListNode *find_pos(ListNode *head, int pos)
    {
        ListNode *res = head;
        while(pos--)
            res = res->next;
        return res;
    }

    void reverse(ListNode *start, ListNode *end)
    {
        ListNode HEAD(0), *cur = start;
        HEAD.next = NULL;
        while(cur != end) {
            ListNode *temp = cur->next;
            cur->next = HEAD.next;
            HEAD.next = cur;
            cur = temp;
        }
        end->next = HEAD.next;
    }
};
