/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) : _cur_node(root) {
    }
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return _cur_node != NULL || !_node_stack.empty();
    }
    /** @return the next smallest number */
    int next() {
        while (!_node_stack.empty() || _cur_node) {
            if (_cur_node) {
                _node_stack.push(_cur_node);
                _cur_node = _cur_node->left;
            } else {
                TreeNode* node = _node_stack.top();
                _node_stack.pop();
                _cur_node = node->right;
                return node->val;
            }
        }
    }
private:
    stack<TreeNode*> _node_stack;
    TreeNode* _cur_node;
};
/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
