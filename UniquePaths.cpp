class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int> > paths(m, vector<int>(n, 0));
        int i, j;
        paths[0][0] = 1;
        for(i = 1; i < m; i++)
            paths[i][0] = paths[i - 1][0];
        for(j = 1; j < n; j++)
            paths[0][j] = paths[0][j - 1];
        for(i = 1; i < m; i++)
            for(j = 1; j < n; j++)
                paths[i][j] = paths[i][j - 1] + paths[i - 1][j];
        return paths[m - 1][n - 1];
    }
};
