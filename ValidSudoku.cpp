class Solution {
public:
    bool isValidSudoku(vector<vector<char> >& board) {
        if (board.size() != 9 || board[0].size() != 9) {
            return false;
        }
        for (int i = 0; i < 9; i++) {
            if (!CheckRow(board, i)) {
                return false;
            }
        }
        for (int i = 0; i < 9; i++) {
            if (!CheckCol(board, i)) {
                return false;
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (!CheckSquar(board, i, j)) {
                    return false;
                }
            }
        }
        return true;
    }
private:
    bool CheckRow(const vector<vector<char> >& board, int row) {
        vector<bool> visited(9, false);
        for (int i = 0; i < board[row].size(); i++) {
            if (board[row][i] == '.') {
                continue;
            }
            if (visited[board[row][i]] == false) {
                visited[board[row][i]] = true;
            } else {
                return false;
            }
        }
        return true;
    }
    bool CheckCol(const vector<vector<char> >& board, int col) {
        vector<bool> visited(9, false);
        for (int i = 0; i < board.size(); i++) {
            if (board[i][col] == '.') {
                continue;
            }
            if (visited[board[i][col]] == false) {
                visited[board[i][col]] = true;
            } else {
                return false;
            }
        }
        return true;
    }
    bool CheckSquar(const vector<vector<char> >& board, int x, int y) {
        vector<bool> visited(9, false);
        for (int i = 3 * x; i < 3 * x + 3; i++) {
            for (int j = 3 * y; j < 3 * y + 3; j++) {
                if (board[i][j] == '.') {
                    continue;
                }
                if (visited[board[i][j]] == false) {
                    visited[board[i][j]] = true;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};
