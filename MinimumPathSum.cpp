class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int row = grid.size(), column = grid[0].size();
        
        int i, j;
        for(i = 1; i < column; i++)
            grid[0][i] += grid[0][i - 1];
        for(i = 1; i < row; i++)
            grid[i][0] += grid[i - 1][0];
        for(i = 1; i < row; i++)
            for(j = 1; j < column; j++)
                grid[i][j] += min(grid[i][j - 1], grid[i - 1][j]);
        return grid[row - 1][column - 1];
    }
};
