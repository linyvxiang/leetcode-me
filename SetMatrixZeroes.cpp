class Solution {
public:
    void clean_row(vector<vector<int>> &matrix, int row_num, int column_num)
    {
        int i;
        for(i = 0; i < column_num; i++)
            matrix[row_num][i] = 0;
    }
    void clean_column(vector<vector<int>> &matrix, int column_num, int row_num)
    {
        int i;
        for(i = 0; i < row_num; i++)
            matrix[i][column_num] = 0;
    }
    void setZeroes(vector<vector<int> > &matrix) {
        int row = matrix.size(), column = matrix[0].size();
        bool zero_row[row], zero_column[column];
        int i, j;
        for(i = 0; i < row; i++)
            zero_row[i] = false;
        for(i = 0; i < column; i++)
            zero_column[i] = false;
        for(i = 0; i < row; i++)
            for(j = 0; j < column; j++)
                if(matrix[i][j] == 0) {
                    zero_row[i] = true;
                    zero_column[j] = true;
                }
        for(i = 0; i < row; i++)
            if(zero_row[i])
                clean_row(matrix, i, column);
        for(j = 0; j < column; j++)
            if(zero_column[j])
                clean_column(matrix, j, row);
    }
};
