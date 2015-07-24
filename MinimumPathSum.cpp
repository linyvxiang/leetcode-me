class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> result(grid.size(), vector<int>(grid[0].size(), 0));
        result[0][0] = grid[0][0];
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (i == 0 && j == 0) {
                    continue;
                } else if (i == 0 && j != 0) {
                    result[i][j] = result[i][j - 1] + grid[i][j];
                } else if (i != 0 && j == 0) {
                    result[i][j] = result[i - 1][j] + grid[i][j];
                } else {
                    result[i][j] = min(result[i - 1][j], result[i][j - 1]) + 
                                    grid[i][j];
                }
            }
        }
        return result[grid.size() - 1][grid[0].size() - 1];
    }
};
