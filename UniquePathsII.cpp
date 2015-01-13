class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if(obstacleGrid.empty())
            return 0;
        int row = obstacleGrid.size(), column = obstacleGrid[0].size();
        int i, j;
        for(i = 0; i < row; i++) {
            for(j = 0; j < column; j++) {
                if(i == 0 && j == 0) {
                    if(obstacleGrid[i][j] == 1)
                        obstacleGrid[i][j] = 0;
                    else
                        obstacleGrid[i][j] = 1;
                } else if(i == 0) {
                    if(obstacleGrid[i][j] == 1)
                        obstacleGrid[i][j] = 0;
                    else
                        obstacleGrid[i][j] = obstacleGrid[i][j - 1];
                } else if(j == 0) {
                    if(obstacleGrid[i][j] == 1)
                        obstacleGrid[i][j] = 0;
                    else
                        obstacleGrid[i][j] = obstacleGrid[i - 1][j];
                } else {
                    if(obstacleGrid[i][j] == 1)
                        obstacleGrid[i][j] = 0;
                    else
                        obstacleGrid[i][j] = obstacleGrid[i - 1][j] +
                                                obstacleGrid[i][j - 1];
                }
            }
        }
        return obstacleGrid[row - 1][column - 1];
    }
};
