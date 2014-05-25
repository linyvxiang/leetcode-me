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
    int maxPathSum(TreeNode *root) {
        max_sum = INT_MIN;
        dfs(root);
        return max_sum;
    }
private:
    int max_sum;
    int dfs(TreeNode *root)
    {
        if(root == NULL)
            return 0;
        int l = dfs(root->left);
        int r = dfs(root->right);
        int sum = root->val;
        if(l > 0)   sum += l;
        if(r > 0)   sum += r;
        max_sum = max(max_sum, sum);
        return max(root->val, max(root->val + l, root->val + r)); //这里要给父结点提供一个"连接" ,所以只可能选左子树+root或者右子树+root或者只有root，而不挠Ω眯纬梢桓鐾暾穆肪� 
    }
};
