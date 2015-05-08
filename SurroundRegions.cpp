class Solution {
public:
    void solve(vector<vector<char> > &board) {
        if(board.empty())
            return ;
		int row_len = board[0].size(), col_len = board.size();
		bool *visited = (bool *)malloc(sizeof(bool) * row_len * col_len);
		memset(visited, false, sizeof(bool) * row_len * col_len);

		int i;
		for(i = 0; i < row_len; i++)
			if(!visited[i] && board[0][i] == 'O')
				bfs(0, i, visited, board);
		for(i = 0; i < col_len; i++)
			if(!visited[i * row_len] && board[i][0] == 'O')
				bfs(i, 0, visited, board);
		for(i = 0; i < col_len; i++)
			if(!visited[i * row_len + row_len - 1] && board[i][row_len - 1] == 'O')
				bfs(i, row_len - 1, visited, board);
		for(i = 0; i < row_len; i++)
			if(!visited[(col_len - 1) * row_len + i] && board[col_len - 1][i] == 'O')
				bfs(col_len - 1, i, visited, board);

		int j;
		for(i = 0; i < col_len; i++)
			for(j = 0; j < row_len; j++)
				if(!visited[i * row_len + j] && board[i][j] == 'O')
					board[i][j] = 'X';
			
			
   }
private:
	bool check_pos(int x, int y, int row_len, int col_len)
	{
		return 0 <= x && x < col_len &&
				0 <= y && y < row_len;
	}
	void bfs(int x, int y, bool *visited, vector<vector<char> > &board)
	{
		queue<int> Q;
		Q.push(x);
		Q.push(y);
		int x_, y_, row_len = board[0].size(), col_len = board.size();
		visited[x * row_len + y] = true;
		int x_f[] = {-1, 1, 0, 0};
		int y_f[] = {0, 0, -1, 1};
		while(!Q.empty()) {
			x_ = Q.front();
			Q.pop();
			y_ = Q.front();
			Q.pop();
//			visited[x_ * row_len + y_] = true;
			int i;
			for(i = 0; i < 4; i++) {
				int n_x = x_ + x_f[i];
				int n_y = y_ + y_f[i];
				if(check_pos(n_x, n_y, row_len, col_len)) {
					if(board[n_x][n_y] == 'O' && !visited[n_x * row_len + n_y]) {
						Q.push(n_x);
						Q.push(n_y);
						visited[n_x * row_len + n_y] = true;
					}
				}

			}

		}

	}
};
