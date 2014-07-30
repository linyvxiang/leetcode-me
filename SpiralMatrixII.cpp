class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > res;
        int *num = (int *)malloc(sizeof(int) * n * n);
        do_generate(1, num, 0, 0, n, n, n);
        int i, j;
        vector<int> temp;
        for(i = 0; i < n; i++) { 
            for(j = 0; j < n; j++)
                temp.push_back(num[i * n + j]);
            res.push_back(temp);
            temp.clear();
        }
        free(num);
        return res;
    }
private:
    void do_generate(int cur_num, int *num, int left_x,
                    int left_y, int len_x, int len_y, int l)
    {
        if(len_x == 0 || len_y == 0)
            return ;
        if(len_x == 1 || len_y == 1) {
            int i, j;
            for(i = left_x; i < left_x + len_y; i++)
                for(j = left_y; j < left_y + len_x; j++)
                    num[i * l + j] = cur_num++;
            return ;
        }
        int i, j;
        for(i = left_x, j = left_y; j < left_y + len_x; j++) 
            num[i * l + j] = cur_num++;
        for(i = left_x + 1, j--; i < left_x + len_y; i++) 
            num[i * l + j] = cur_num++;
        for(i--, j--; j >= left_y; j--)
            num[i * l + j] = cur_num++;
        for(i--, j++; i > left_x; i--)
            num[i * l + j] = cur_num++;
        do_generate(cur_num, num, left_x + 1, left_y + 1, len_x - 2, len_y -2, l);
    }
};
