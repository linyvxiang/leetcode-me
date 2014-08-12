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
			RandomListNode *cur = head;
			while(cur) {
				RandomListNode *tmp = (RandomListNode *)malloc(sizeof(struct RandomListNode));
				tmp->label = cur->label;
				tmp->next = cur->next;
				tmp->random = NULL;
				cur->next = tmp;
				cur = tmp->next;
			}

			cur = head;
			while(cur) {
				if(cur->random) {
					cur->next->random = cur->random->next;
				}
				cur = cur->next->next;
			}
			RandomListNode RES_HEAD(0), *tail = &RES_HEAD;
			cur = head;
			while(cur) {
				tail->next = cur->next;
				tail = cur->next;
				cur->next = cur->next->next;
				cur = cur->next;
			}
			tail->next = NULL;
			return RES_HEAD.next;
		}
};
