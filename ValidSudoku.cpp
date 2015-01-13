class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        return check_row(board) && check_col(board)
                    && check_block(board);
    }
private:
    bool check_row(const vector<vector<char> > &board)
    {
        for(int i = 0; i < 9; i++) {
            vector<bool> flag(10, false);
            for(int j = 0; j < 9; j++) {
                if(!(board[i][j] >= '0' && board[i][j] <= '9'))
                    continue;
                if(flag[board[i][j] - '0'])
                    return false;
                flag[board[i][j] - '0'] = true;
            }
        }
        return true;
    }
    bool check_col(const vector<vector<char> > &board)
    {
        for(int i = 0; i < 9; i++) {
            vector<bool> flag(10, false);
            for(int j = 0; j < 9; j++) {
                if(!(board[j][i] >= '0' && board[j][i] <= '9'))
                    continue;
                if(flag[board[j][i] - '0'])
                    return false;
                flag[board[j][i] - '0'] = true;
            }
        }
        return true;
    }
    bool check_block(const vector<vector<char> > &board)
    {
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                vector<bool> flag(false, 10);
                for(int x = i * 3; x < i * 3 + 3; x++) {
                    for(int y = j * 3; y < j * 3 + 3; y++) {
                        if(!(board[x][y] >= '0' && board[x][y] <= '9'))
                            continue;
                        if(flag[board[x][y] - '0'])
                            return false;
                        flag[board[x][y] -'0'] = true;
                    }
                }
            }
        }
        return true;
    }
};
