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
        
        ListNode *cur = head;
        while(cur) {
           ListNode *tail = find_tail(cur);
           if(!tail || tail == cur)
               break;
           tail->next = cur->next;
           cur->next = tail;
           cur = tail->next;
        }
    }
private:
    ListNode *find_tail(ListNode *start)
    {
      ListNode *cur = start;
      ListNode *pre = NULL, *ppre = NULL;
      while(cur) {
          ppre = pre;
          pre = cur;
          cur = cur->next;
      }
      // pre is the tail;
      if(ppre)
          ppre->next = NULL;
      return pre;
    }
};
