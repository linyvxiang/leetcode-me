/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *create_bst_tree(int start, int end, ListNode* &list)
    {
        if(start > end)
            return NULL;
        int mid = start + (end - start) / 2;
        TreeNode *left_child = create_bst_tree(start, mid - 1, list);
        TreeNode *parent = new TreeNode(list->val);
        parent->left = left_child;
        list = list->next;
        parent->right = create_bst_tree(mid + 1, end, list);
        return parent;
    }
    TreeNode *sortedListToBST(ListNode *head) {
        if(!head)
            return NULL;
        ListNode *cur = head;
        int len = 0;
        while(cur) {
            len++;
            cur = cur->next;
        }
        
        return create_bst_tree(0, len - 1, head);
    }
};
