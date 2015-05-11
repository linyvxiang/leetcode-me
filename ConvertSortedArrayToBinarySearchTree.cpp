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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return create_bst(nums, 0, nums.size() - 1);
    }
private:
    TreeNode* create_bst(const vector<int>& nums, int start, int end) {
        if (start > end) {
            return NULL;
        }
        int mid = (start + end) >> 1;
        TreeNode* root = (TreeNode *)malloc(sizeof(struct TreeNode));
        root->val = nums[mid];
        root->left = create_bst(nums, start, mid - 1);
        root->right = create_bst(nums, mid + 1, end);
        return root;
    }
};
