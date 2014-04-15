/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head)
            return head;
        RandomListNode SRC_HEAD(0), DST_HEAD(0), *src_cur = head, *dst_cur;
        dst_cur = &DST_HEAD;
        SRC_HEAD.next = head;
        while(src_cur) {
            RandomListNode *tmp = (RandomListNode *)malloc(sizeof(struct RandomListNode));
            tmp->next = src_cur->next;
            tmp->random = NULL;
            tmp->label = src_cur->label;
            src_cur->next = tmp;
            src_cur = tmp->next;
        }
        src_cur = SRC_HEAD.next;
        DST_HEAD.next = head->next;
        dst_cur = &DST_HEAD;
        while(src_cur) {
            if(src_cur->random) {
                src_cur->next->random = src_cur->random->next;
            }
            src_cur = src_cur->next->next;
        }
        
        src_cur = SRC_HEAD.next;
        while(src_cur) {
            dst_cur->next = src_cur->next;
            dst_cur = dst_cur->next;
            src_cur->next = src_cur->next->next;
            src_cur = src_cur->next;
        }
        return DST_HEAD.next;
    }
};
