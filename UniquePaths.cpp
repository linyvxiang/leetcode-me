class Solution {
public:
    int uniquePaths(int m, int n) {
        int res[m][n];
        int i, j;
        for(i = 0; i < n; i++)
            res[0][i] = 1;
        for(i = 0; j < m; i++)
            res[i][0] = 1;
        for(i = 1; i < m; i++)
            for(j = 1; j < n; j++)
                res[i][j] = res[i - 1][j] + res[i][j - 1];
        return res[m - 1][n - 1];
    }
};
