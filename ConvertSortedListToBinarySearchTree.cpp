class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if (!head) {
            return NULL;
        }
        int len = get_list_len(head);
        return construct_bst(head, 0, len - 1);
    }
private:
    int get_list_len(ListNode* head) {
        int len = 0;
        while (head) {
            len++;
            head = head->next;
        }
        return len;
    }
    TreeNode* construct_bst(ListNode* &cur_node, int start, int end) {
        if (start > end) {
            return NULL;
        }
        int mid = (start + end) / 2;
        TreeNode* left_tree = construct_bst(cur_node, start, mid - 1);
        TreeNode* root_node = (TreeNode *)malloc(sizeof(struct TreeNode));
        root_node->val = cur_node->val;
        cur_node = cur_node->next;
        root_node->left = left_tree;
        root_node->right = construct_bst(cur_node, mid + 1, end);
        return root_node;
    }
};
