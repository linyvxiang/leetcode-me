class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > res(n, vector<int>(n, 0));
        if(n == 0)
            return res;
        int cur_num = 1;
        do_trans(res, cur_num, 0, 0, res[0].size(), res.size());
        return res;
    }
private:
    void do_trans(vector<vector<int> > &matrix, int &cur_num, int left_x,
                    int left_y, int len_x, int len_y)
    {
        if(len_x == 0 || len_y == 0)
            return ;
        if(len_x == 1 || len_y == 1) {
            int i, j;
            for(i = left_x; i < left_y + len_y; i++) {
                for(j = left_y; j < left_y + len_x; j++) {
                    matrix[i][j] = cur_num++;
                }
            }
            return ;
        }
        int i, j;
        for(i = left_y; i < left_x + len_x; i++)
            matrix[left_x][i] = cur_num++;
        for(i--, j = left_x + 1; j < left_y + len_y; j++)
            matrix[j][i] = cur_num++;
        for(j--, i--; i >= left_y; i--)
            matrix[j][i] = cur_num++;
        for(i++, j--; j > left_x; j--)
            matrix[j][i] = cur_num++;

        do_trans(matrix, cur_num, left_x + 1, left_y + 1, len_x - 2, len_y - 2);

    }
};
