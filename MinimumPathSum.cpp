class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int m = grid.size();
        int n = grid[0].size();
        if(m == 0 || n == 0)
            return 0;
        
        int i, j, path_sum[m][n];
        path_sum[0][0] = grid[0][0];
    	for(i = 1; i < m; ++i)
	    	path_sum[i][0] = path_sum[i - 1][0] + grid[i][0];
    	for(j = 1; j < n; ++j)
	    	path_sum[0][j] = path_sum[0][j - 1] + grid[0][j];
            
	    for(i = 1; i < m; ++i)
	    	for(j= 1; j < n; ++j)
		    	path_sum[i][j] = min(path_sum[i - 1][j], path_sum[i][j - 1])+ grid[i][j];
        return path_sum[m - 1][n - 1];
            
    }
};
