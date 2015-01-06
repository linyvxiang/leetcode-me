class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        if(grid.empty())
            return 0;
        int row = grid.size(), column = grid[0].size();
        int i, j;
        for(i = 0; i < row; i++) {
            for(j = 0; j < column; j++) {
                if(i == 0 && j == 0)
                    continue;
                if(i == 0) {
                    grid[i][j] += grid[i][j - 1];
                } else if(j == 0) {
                    grid[i][j] += grid[i - 1][j];
                } else {
                    grid[i][j] += min(grid[i - 1][j], 
                                    grid[i][j - 1]);
                }
            }
        }
        return grid[row - 1][column - 1];
    }
};
