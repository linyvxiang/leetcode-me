class Solution {
    public:
        bool exist(vector<vector<char> > &board, string word) {
            int row = board.size(), column = board[0].size();
            vector<vector<bool> > visit_flag(row, vector<bool>(column, false));
            int i, j;
            for(i = 0; i < row; i++) {
                for(j = 0; j < column; j++) {
                    if(board[i][j] == word[0]) {
                        if(dfs_search(board, 0, i, j, word, visit_flag))
                            return true;
                    }
                }
            }
            return false;
        }
    private:
        bool dfs_search(const vector<vector<char> > &board,
                            int cur_word_pos, int cur_x, int cur_y,
                            const string &word, 
                            vector<vector<bool> > &visit_flag)
        {
            if(cur_word_pos == word.size())
                return true;
            if(cur_x < 0 || cur_x >= board.size())
                return false;
            if(cur_y < 0 || cur_y > board.size())
                return false;
            if(visit_flag[cur_x][cur_y] || board[cur_x][cur_y] != word[cur_word_pos])
                return false;
            visit_flag[cur_x][cur_y] = true;
            bool ret = dfs_search(board, cur_word_pos + 1, cur_x, cur_y - 1, word, visit_flag) ||
                       dfs_search(board, cur_word_pos + 1, cur_x - 1, cur_y, word, visit_flag) ||
                       dfs_search(board, cur_word_pos + 1, cur_x, cur_y + 1, word, visit_flag) ||
                       dfs_search(board, cur_word_pos + 1, cur_x + 1, cur_y, word, visit_flag);
            visit_flag[cur_x][cur_y] = false;
            return ret;
        }
};
