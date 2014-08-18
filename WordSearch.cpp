class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        if(word.size() == 0)
            return true;
        if(board.empty())
            return false;
        int m = board.size(), n = board[0].size();
        vector<vector<bool> > flag(m, vector<bool>(n, false));
        int x, y;
        for(x = 0; x < board.size(); x++)
            for(y = 0; y < board[x].size(); y++)
                if(do_judge(board, word, x, y, 0, flag))
                    return true;
           
        return false;
    }
private:
    bool do_judge(vector<vector<char> > &board, string &str,
                    int x, int y, int cur_pos, vector<vector<bool> > &flag)
    {
        if(cur_pos == str.size())
            return true;
        if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || flag[x][y])
            return false;
        if(str[cur_pos] != board[x][y])
            return false;
        flag[x][y] = true;
        bool ret = do_judge(board, str, x, y - 1, cur_pos + 1, flag) ||
                    do_judge(board, str, x - 1, y, cur_pos + 1, flag) ||
                     do_judge(board, str, x, y + 1, cur_pos + 1, flag) ||
                      do_judge(board, str, x + 1, y, cur_pos + 1, flag);
        flag[x][y] = false;
        return ret;
    }
};
