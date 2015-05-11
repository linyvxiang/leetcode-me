/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) {
            return NULL;
        }
        int len = get_len(head);
        ListNode* cur_node = head;
        return create_bst(cur_node, 0, len - 1);
    }
private:
    int get_len(ListNode* &head) {
        int len = 0;
        ListNode* cur = head;
        while (cur) {
            len++;
            cur = cur->next;
        }
        return len;
    }
    TreeNode* create_bst(ListNode* &cur_node, int start, int end) {
        if (start > end) {
            return NULL;
        }
        int mid = (start + end) >> 1;
        TreeNode* left = create_bst(cur_node, start, mid - 1);
        TreeNode* root = (TreeNode *)malloc(sizeof(struct TreeNode));
        root->val = cur_node->val;
        root->left = left;
        cur_node = cur_node->next;
        root->right = create_bst(cur_node, mid + 1, end);
        return root;
    }
};