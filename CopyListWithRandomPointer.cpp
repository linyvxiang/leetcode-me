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
				RandomListNode *tmp = (RandomListNode *)malloc(sizeof(RandomListNode));

				tmp->next = NULL;
				tmp->random = NULL;
				tmp->label = cur->label;
				tmp->next = cur->next;
				cur->next = tmp;
				cur = tmp->next;
			}// first round
			cur = head;
			while(cur) {
				if(cur->random) {
					cur->next->random = cur->random->next;
				}
				cur = cur->next->next;
			}
			RandomListNode HEAD(0);
			RandomListNode *tail = &HEAD;
			cur = head;
			while(cur) {
				tail->next = cur->next;
				cur->next = cur->next->next;
				cur = cur->next;
				tail = tail->next;
			}
			return HEAD.next;
		}
};
