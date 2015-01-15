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
    ListNode *swapPairs(ListNode *head) {
        ListNode *cur_node = head, *cur_tail, *next_node;
        ListNode HEAD(0);
        ListNode *ret_tail = &HEAD;
        while(cur_node) {
            cur_tail = get_cur_group(cur_node, 2);
            if(!cur_tail) {
                ret_tail->next = cur_node;
                break;
            }
            next_node = cur_tail->next;
            cur_tail->next = NULL;
            reverse_group(cur_node, cur_tail);
            ret_tail->next = cur_node;
            ret_tail = cur_tail;
            cur_node = next_node;
        }
        return HEAD.next;
    }
private:
    ListNode *get_cur_group(ListNode *cur_node, int k)
    {
        ListNode *ret = cur_node;
        for(int i = 1; i < k; i++) {
            if(ret == NULL) {
                ret = NULL;
                break;
            }
            ret = ret->next;
        }
        return ret;
    }
    void reverse_group(ListNode* &head, ListNode* &tail)
    {
        ListNode HEAD(0);
        ListNode *cur_node = head;
        while(cur_node) {
            ListNode *tmp = cur_node->next;
            cur_node->next = HEAD.next;
            HEAD.next = cur_node;
            cur_node = tmp;
        }
        swap(head, tail);
    }
};
