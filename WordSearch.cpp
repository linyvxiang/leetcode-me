class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        int row = board.size();
        int column = board[0].size();
        bool *flag = (bool *)malloc(sizeof(bool));
        memset(flag, false, sizeof(flag));
        int i, j;
        for(i = 0; i < row; i++) {
            for(j = 0; j < column; j++) {
                if(board[i][j] == word[0] && !check_visit(i, j, flag, board)) {
                    memset(flag, false, sizeof(flag));
                    mark(i, j, flag, board);
                    bool res = do_search_word(i, j, 1, flag, board, word);
                    if(res)
                        return true;
                    unmark(i, j, flag, board);
                }
            }
        }
        free(flag);
        return false;
    }
private:
    bool check_visit(int x, int y, bool *flag, vector<vector<char> > &board)
    {
        return flag[x * board[0].size() + y];
    }
    void mark(int x, int y, bool *flag, vector<vector<char> > &board)
    {
        flag[x * board[0].size() + y] = true;
    }
    void unmark(int x, int y, bool *flag, vector<vector<char> > &board)
    {
        flag[x * board[0].size() + y] = false;
    }
    bool check_out(int x, int y, vector<vector<char> > &board)
    {
        if(x < 0 || x >= board.size()
            ||  y < 0 || y >= board[0].size())
            return true;

        return false;
    }
    bool do_search_word(int cur_x, int cur_y, int cur_pos, bool *flag, 
                        vector<vector<char> > &board, string &word)
    {
        if(cur_pos == word.size())
            return true;
        int dir[4][2] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0}};
        int i;
        for(i = 0; i < 4; i++) {
            int x = cur_x + dir[i][0], y = cur_y + dir[i][1];
            if(check_out(x, y, board))
                continue;
            if(board[x][y] == word[cur_pos] && !check_visit(x, y, flag, board)) {
                mark(x, y, flag, board);
                bool res = do_search_word(x, y, cur_pos + 1, flag, board, word);
                unmark(x, y, flag, board);
                if(res)
                    return true;
            }
        }

        return false;
    }

};
