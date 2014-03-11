class Solution {
public:
	bool check_row(vector<char> row)
	{
		int i;
		bool visited[10] = {false};
		for(i = 0; i < 9; i++) {
		    if(row[i] == '.')
		        continue;
			if(visited[row[i] - '0'])
				return false;
			visited[row[i] - '0'] = true;
		}
		return true;
	}
	bool check_column(vector<vector<char>> board, int column)
	{
		int i;
		bool visited[10] = {false};
		for(i = 0; i < 9; i++) {
		    if(board[i][column] == '.')
		        continue;
			if(visited[board[i][column] - '0'])
				return false;
		    visited[board[i][column] - '0'] = true;
		}	
		return true;
	}
	bool check_sub_section(vector<vector<char>> board, int row, int column)
	{
		// row and column is the left up position of the sub_section
		int i, j;
		bool visited[10] = {false};
		for(i = row * 3; i < row * 3 + 3; i++)
			for(j = column * 3; j < column * 3 + 3; j++) {
			    if(board[i][j] == '.')
			        continue;
				if(visited[board[i][j] - '0'])
					return false;
			    visited[board[i][j] - '0'] = true;
		}
		return true;
	}
    bool isValidSudoku(vector<vector<char> > &board) {
        int i, j;
    	for(i = 0; i < 9; i++)
			if(!check_row(board[i]))
				return false;
		for(i = 0; i < 9; i++)
			if(!check_column(board, i))
				return false;
		for(i = 0; i < 3; i++)
			for(j = 0; j < 3; j++)
				if(!check_sub_section(board, i, j))
					return false;
		return true;
    }
};
