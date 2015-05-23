class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int num = 1;
        vector<vector<int> > ret(n, vector<int>(n, 0));
        int cur_len = n - 1;
        int cur_x = 0;
        int cur_y = 0;
        while (cur_len >= 0) {
            if (cur_len == 0) {
                for (int i = cur_y; i <= cur_y + cur_len; i++) {
                    ret[cur_x][i] = num++;
                }
                break;
            }
            int i;
            for (i = cur_x; i < cur_y + cur_len; i++) {
                ret[cur_x][i] = num++;
            }
            cur_y = i;
            for (i = cur_x; i < cur_x + cur_len; i++) {
                ret[i][cur_y] = num++;
            }
            cur_x = i;
            int y = cur_y;
            for (; cur_y > y - cur_len; cur_y--) {
                ret[cur_x][cur_y] = num++;
            }
            int x = cur_x;
            for (; cur_x > x - cur_len; cur_x--) {
                ret[cur_x][cur_y] = num++;
            }
            cur_x++;
            cur_y++;
            cur_len -= 2;
        }
        return ret;
    }
};
