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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;
        do_generate_path(root, "", ret);
        return ret;
    }
private:
    void num_to_str(int val, string& str) {
        bool negative = false;
        if (val < 0) {
            negative = true;
            val *= -1;
        }
        do {
            str += val % 10 + '0';
            val /= 10;
        } while (val);
        if (negative) {
            str.append("-");
        }
        reverse(str.begin(), str.end());
    }
    void do_generate_path(TreeNode* root, string cur_str, vector<string>& ret) {
        if (!root) {
            return;
        }
        string num_str;
        num_to_str(root->val, num_str);
        if (!cur_str.empty()) {
            cur_str += "->";
        }
        cur_str += num_str;
        if (!root->left && !root->right) {
            ret.push_back(cur_str);
            return;
        } else {
            if (root->left) {
                do_generate_path(root->left, cur_str, ret);
            }
            if (root->right) {
                do_generate_path(root->right, cur_str, ret);
            }
        }
            
    }
};
