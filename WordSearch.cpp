class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == word[0]) {
                    vector<vector<bool> > visited(board.size(),
                            vector<bool>(board[0].size(), false));
                    bool ret = check_exist(board, visited, i, j, 0, word);
                    if (ret) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
private:
    bool check_legal(const vector<vector<char> >& board,
                     const vector<vector<bool> >& visited,
                     int x, int y) {
        return 0 <= x && x < board.size() &&
                0 <= y && y < board[0].size() &&
                    visited[x][y] == false;
    }
    bool check_exist(const vector<vector<char> >& board,
                     vector<vector<bool> >& visited,
                     int x, int y, int cur_pos,
                     const string& word) {
        cur_pos++;
        if (cur_pos == word.size()) {
            return true;
        }
        visited[x][y] = true;
        if (check_legal(board, visited, x - 1, y) &&
                board[x - 1][y] == word[cur_pos]) {
            bool ret = check_exist(board, visited, x - 1,
                                     y, cur_pos, word);
            if (ret) {
                return true;
            }
            visited[x - 1][y] = false;
        }
        if (check_legal(board, visited, x + 1, y) &&
                board[x - 1][y] == word[cur_pos]) {
            bool ret = check_exist(board, visited, x + 1,
                                     y, cur_pos, word);
            if (ret) {
                return true;
            }
            visited[x + 1][y] = false;
        }
        if (check_legal(board, visited, x, y - 1) &&
                board[x][y - 1] == word[cur_pos]) {
            bool ret = check_exist(board, visited, x,
                                     y - 1, cur_pos, word);
            if (ret) {
                return true;
            }
            visited[x][y - 1] = false;
        }
        if (check_legal(board, visited, x, y + 1) &&
                board[x][y + 1] == word[cur_pos]) {
            bool ret = check_exist(board, visited, x,
                                     y + 1, cur_pos, word);
            if (ret) {
                return true;
            }
            visited[x][y + 1] = false;
        }
        return false;
    }
};
