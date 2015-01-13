class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int row = matrix.size(), column = matrix[0].size(); 
        int i, j;
        bool first_row_zero =  false, first_column_zero = false;

        for(i = 0; i < column; i++) {
            if(matrix[0][i] == 0) {
                first_row_zero = true;
                break;
            }
        }
        for(i = 0; i < row; i++) {
            if(matrix[i][0] == 0) {
                first_column_zero = true;
                break;
            }
        }
        for(i = 1; i < row; i++) {
            for(j = 1; j < column; j++) {
                if(matrix[i][j] == 0)
                    matrix[i][0] = matrix[0][j] = 0;
            }
        }
        for(i = 1; i < row; i++) {
            for(j = 1; j < column; j++) {
                if(matrix[0][j] == 0 || matrix[i][0] == 0)
                    matrix[i][j] = 0;
            }
        }
        if(first_row_zero)
            for(i = 0; i < column; i++)
                matrix[0][i] = 0;
        if(first_column_zero)
            for(i = 0; i < row; i++)
                matrix[i][0] = 0;

      }
};
