class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        if (matrix.empty()) {
            return ret;
        }
        int cur_x = 0;
        int cur_y = 0;
        int cur_x_len = matrix[0].size() - 1;
        int cur_y_len = matrix.size() - 1;
        while (cur_x_len >= 0 && cur_y_len >= 0) {
            if (cur_y_len == 0) {
                for (int i = cur_y; i <= cur_y + cur_x_len; i++) {
                    ret.push_back(matrix[cur_x][i]);
                }
                break;
            }
            if (cur_x_len == 0) {
                for (int i = cur_x; i <= cur_x + cur_y_len; i++) {
                    ret.push_back(matrix[i][cur_y]);
                }
                break;
            }
            int i;
            for (i = cur_x; i < cur_y + cur_x_len; i++) {
                ret.push_back(matrix[cur_x][i]);
            }
            cur_y = i;
            for (i = cur_x; i < cur_x + cur_y_len; i++) {
                ret.push_back(matrix[i][cur_y]);
            }
            cur_x = i;
            int y = cur_y;
            for (; cur_y > y - cur_x_len; cur_y--) {
                ret.push_back(matrix[cur_x][cur_y]);
            }
            int x = cur_x;
            for (; cur_x > x - cur_y_len; cur_x--) {
                ret.push_back(matrix[cur_x][cur_y]);
            }
            cur_x++;
            cur_y++;
            cur_x_len -= 2;
            cur_y_len -= 2;
        }
        return ret;
    }
};
