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
    TreeNode* sortedListToBST (ListNode* head) {
        if(!head)
            return NULL;
        ListNode *p = head;
        int len = 0;
        while(p)
        {
             len++;
             p = p->next;
        }
        return create_tree(head, 0, len - 1);
    }
private:
    TreeNode *create_tree(ListNode* &list, int start, int end)
    {
        if(start > end)
            return NULL;
        int mid = (start + end) / 2;
        TreeNode *left = create_tree(list, start, mid - 1);
        TreeNode *root = (TreeNode *)malloc(sizeof(struct TreeNode));
        memset(root, 0, sizeof(struct TreeNode));
        root->left = left;
        root->val = list->val;
        list = list->next;
        root->right = create_tree(list, mid + 1, end);
        return root;
    }
};
