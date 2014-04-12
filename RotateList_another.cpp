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
      if(!head || !k)
        return head;
      ListNode HEAD(0), *cur_pos = head;
      ListNode *pre = NULL;
      HEAD.next = head;
      int len = 0;
      while(cur_pos) {
          len++;
          pre = cur_pos;
          cur_pos = cur_pos->next;
      }// now we know the length of the list is len;
      k = k % len;
      k = len - k;
      if(!k)
        return head;
      //next we want to find the k-1th node of the list
      cur_pos = HEAD.next;
      int cur_len = 1;
      while(cur_len <= k - 1) {
          cur_len++;
          cur_pos = cur_pos->next;
      }// ok the cur_pos->next should be the new head
      pre->next = HEAD.next;
      HEAD.next = cur_pos->next;
      cur_pos->next = NULL;
      return HEAD.next;
    }
};
