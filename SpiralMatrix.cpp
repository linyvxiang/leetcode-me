class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> res;
        if(matrix.size() != 0)
            do_trans(matrix, res, 0, 0, matrix[0].size(), matrix.size());
        return res;
    }
private:
    void do_trans(vector<vector<int> > &matrix, vector<int> &res, int left_x,
                    int left_y, int len_x, int len_y)
    {
        if(len_x == 0 || len_y == 0)
            return ;
        if(len_x == 1 || len_y == 1) {
            int i, j;
            for(i = left_x; i < left_y + len_y; i++) {
                for(j = left_y; j < left_y + len_x; j++) {
                    res.push_back(matrix[i][j]);
                }
            }
            return ;
        }
        int i, j;
        for(i = left_y; i < left_x + len_x; i++)
            res.push_back(matrix[left_x][i]);
        for(i--, j = left_x + 1; j < left_y + len_y; j++)
            res.push_back(matrix[j][i]);
        for(j--, i--; i >= left_y; i--)
            res.push_back(matrix[j][i]);
        for(i++, j--; j > left_x; j--)
            res.push_back(matrix[j][i]);

        do_trans(matrix, res, left_x + 1, left_y + 1, len_x - 2, len_y - 2);

    }
};
