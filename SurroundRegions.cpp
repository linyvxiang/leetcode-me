class Solution {
public:
    void solve(vector<vector<char> > &board) {
        if(board.size() == 0)
            return ;
        int row = board.size();
        int column = board[0].size(), i, j;
        //bool visited[row][column];
        bool *visited = (bool *)malloc(sizeof(bool) * row * column);
        for(i = 0; i < row; i++)
            for(j = 0; j < column; j++)
                visited[i * column + j] = false;

        for(i = 0; i < column; i++) {
            if(board[0][i] == 'O' && !(visited[0 * column + i]))
                bfs(0, i, board, visited);
        }
        for(i = 0; i < row; i++) {
            if(board[i][0] == 'O' && !(visited[i * column + 0]))
                bfs(i, 0, board, visited);
        }
        for(i = 0; i < row; i++) {
            if(board[i][column - 1] == 'O' && !(visited[i * column + column - 1]))
                bfs(i, column - 1, board, visited);
        }
        for(i = 0; i < column; i++) {
            if(board[row -1][i] == 'O' && !(visited[column * (row - 1) + i]))
                bfs(row - 1, i, board, visited);
        }
        for(i = 0; i < row; i++)
            for(j = 0; j < column; j++)
                if(board[i][j] == '+')
                    board[i][j] = 'O';
                else if(board[i][j] == 'O')
                    board[i][j] = 'X';
    }
private:
    bool check_pos(int row, int column, vector<vector<char> > &board)
    {
        return 0 <= row && row < board.size() && 0 <= column && column < board.size();
    }
    void bfs(int r, int c, vector<vector<char> > &board, bool *visited)
    {
        queue<int> Q;
        int n = board[0].size();
        Q.push(r);
        Q.push(c);
        visited[r * n + c] = true;
        board[r][c] = '+';
        while(!Q.empty()) {
            int _r = Q.front();
            Q.pop();
            int _c = Q.front();
            Q.pop();
            board[_r][_c] = '+';
            if(check_pos(_r - 1, _c, board) && board[_r - 1][_c] == 'O' && !(visited[(_r - 1 ) * n + _c])) {
                visited[(_r - 1 ) * n + _c] = true;
                Q.push(_r -1);
                Q.push(_c);
            }
            if(check_pos(_r, _c - 1, board) && board[_r][_c - 1] == 'O' && !(visited[_r * n + _c - 1])) {
                visited[_r * n + _c - 1] = true;
                Q.push(_r);
                Q.push(_c - 1);
            }
            if(check_pos(_r + 1, _c, board) && board[_r + 1][_c] == 'O' && !(visited[(_r + 1) * n + _c])) {
                visited[(_r + 1) * n + _c] = true;
                Q.push(_r + 1);
                Q.push(_c);
            }
            if(check_pos(_r, _c + 1, board) && board[_r][_c + 1] == 'O' && !(visited[_r * n + _c + 1])) {
                visited[_r * n + _c + 1] = true;
                Q.push(_r);
                Q.push(_c + 1);
            }
        }
    }
};
