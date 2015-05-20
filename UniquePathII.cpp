class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0][0] == 1) {
            return 0;
        }
        vector<vector<int> > path(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 0));
        for (int i = 0; i < path.size(); i++) {
            for (int j = 0; j < path[0].size(); j++) {
                if (obstacleGrid[i][j] == 1) {
                    path[i][j] = 0;
                    continue;
                }
                if (i == 0 && j == 0) {
                    path[i][j] = 1;
                } else if (i == 0) {
                    path[i][j] = obstacleGrid[i][j - 1] == 1 ? 0 : path[i][j - 1];
                } else if (j == 0) {
                    path[i][j] = obstacleGrid[i - 1][j] == 1 ? 0 : path[i - 1][j];
                } else {
                    if (obstacleGrid[i][j - 1] == 1 && obstacleGrid[i - 1][j] == 1) {
                        path[i][j] = 0;
                    } else if (obstacleGrid[i][j - 1] == 1) {
                        path[i][j] = path[i - 1][j];
                    } else if (obstacleGrid[i - 1][j] == 1) {
                        path[i][j] = path[i][j - 1];
                    } else {
                        path[i][j] = path[i][j - 1] + path[i - 1][j];
                    }
                }
            }
        }
        return path[path.size() - 1][path[0].size() - 1];
      }
};
