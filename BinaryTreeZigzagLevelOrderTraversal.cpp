class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        stack<TreeNode *> odd_level;
        stack<TreeNode *> even_level;
        vector<vector<int>> V;
        vector<int> res;
        
        
        if(!root)
            return V;
        int cur_level_len = 1, next_level_len = 0;
        int cur_level = 1;
        odd_level.push(root);
        
        while((cur_level % 2 == 1 && !odd_level.empty() || cur_level % 2 == 0 && !even_level.empty())) {
            if(cur_level % 2 == 1) { //cur level is an odd level so push the children to even stack
                if((odd_level.top())->left) {
                    even_level.push((odd_level.top())->left);
                    next_level_len++;
                }
                if((odd_level.top())->right) {
                    even_level.push((odd_level.top())->right);
                    next_level_len++;
                }
                res.push_back((odd_level.top())->val);
                odd_level.pop();
            } else {  // cur level is an even level so push the children to odd stak but note that right first and then left(easy to forget )
                if((even_level.top())->right) {
                    odd_level.push((even_level.top())->right);
                    next_level_len++;
                }
                if((even_level.top())->left) {
                    odd_level.push((even_level.top())->left);
                    next_level_len++;
                }
                res.push_back((even_level.top())->val);
                even_level.pop();
            }
            cur_level_len--;
            
            if(!cur_level_len) {
                cur_level_len = next_level_len;
                next_level_len = 0;
                cur_level++;
                V.push_back(res);
                res.clear();
            }
        }
        
      return move(V);  
    }
};
