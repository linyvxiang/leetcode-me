class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int i, j, n = matrix.size();
        for(i = 0; i < n; i++)
            for(j = 0; j < n - i; j++)
                swap(matrix[i][j], matrix[n - 1 - j][n -  1 - i]);
        for(i = 0; i < n / 2; i++)
            for(j = 0; j < n; j++)
                swap(matrix[i][j], matrix[n - 1 - i][j]);
    }
};
