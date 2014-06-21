Unique paths II
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int col_num = obstacleGrid[0].size(), row_num = obstacleGrid.size();
        int i, j;
        int res[row_num][col_num];
        bool flag  = false;
        for(i = 0; i < col_num; i++) {
            if(!flag && obstacleGrid[0][i] == 0)
                res[0][i] = 1;
            else if(!flag && obstacleGrid[0][i] == 1) {
                flag = true;
                res[0][i] = 0;
            }
            else
                res[0][i] = 0;
        }
        flag = false;
        for(i = 0; i < row_num; i++) {
            if(!flag && obstacleGrid[i][0] == 0)
                res[i][0] = 1;
            else if(!flag && obstacleGrid[i][0] == 1) {
                flag = true;
                res[i][0] = 0;
            }
            else
                res[i][0] = 0;
        }// init finished
        if(obstacleGrid[0][0] == 1 || obstacleGrid[row_num - 1][col_num - 1] == 1)
            return 0;
        for(i = 1; i < row_num; i++)
            for(j = 1; j < col_num; j++) {
                if(obstacleGrid[i][j] == 1)
                    res[i][j] = 0;
                else
                    res[i][j] = res[i - 1][j] + res[i][j - 1];
            }
        return res[row_num - 1][col_num - 1];
    }
};
