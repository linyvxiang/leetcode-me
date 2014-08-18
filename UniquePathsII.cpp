class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int row = obstacleGrid.size(), column = obstacleGrid[0].size();
        vector<vector<int> > paths(row, vector<int>(column, 0));
        int i, j;
        paths[0][0] = obstacleGrid[0][0] == 1 ? 0 : 1;

        for(i = 1; i < column; i++)
            paths[0][i] = obstacleGrid[0][i] == 1 ? 0 : paths[0][i - 1];
        for(j = 1; j < row; j++)
            paths[j][0] = obstacleGrid[j][0] == 1 ? 0 : paths[j - 1][0];

        for(i = 1; i < row; i++)
            for(j = 1; j < column; j++) {
                if(obstacleGrid[i][j] == 1)
                    paths[i][j] = 0;
                else
                    paths[i][j] = paths[i][j - 1] + paths[i - 1][j];
            }
        return paths[row - 1][column - 1];
    }
};
