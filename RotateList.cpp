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
    ListNode *rotateRight(ListNode *head, int k) {
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *__head = (ListNode *)malloc(sizeof(ListNode));
        __head->next = head;
        int step = 0;
        if(!head)
            return NULL;

        int len = 0;
        while(slow) {
            len++;
            slow = slow->next;
        }
        if(len == 1)
            return head;
        if(k > len)
            k = k % len;
        if(k == 0)
            return head;
        slow = head;
        for(; step < k; step++) {
            fast = fast->next;
            if(!fast)
                return head;
        }

        while(fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        //now break it and reverse
        ListNode *tmp = __head->next;
        __head->next = slow->next;
        fast->next = tmp;
        slow->next = NULL;
        return __head->next;
    }
};
