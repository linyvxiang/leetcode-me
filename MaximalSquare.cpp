class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = 0;
        int col = 0;
        int max_area = 0;
        while (row < matrix.size()) {
            col = 0;
            while (col < matrix[0].size()) {
                int right = col;
                while (right < matrix[0].size() &&
                        matrix[row][right] == '1') {
                    right++;
                }
                int down = row;
                while (down < matrix.size() &&
//                        down - row <= right - col &&
                        matrix[down][col] == '1') {
                    down++;
                }
                int len = check_all_one(matrix, row, col, right, down);
                if (len) {
                    max_area = max(max_area, len * len);
                    col++;
                } else {
                    col++;
                }
            }
            row++;
        }
        return max_area;
    }
private:
    int check_all_one(const vector<vector<char>>& matrix,
            int row, int col, int right, int down) {
        int len = min(down - row, right - col);
        if (len == 0) {
            return false;
        }
        for (int l = 0; l < len; l++) {
            for (int i = 0; i <= l; i++) {
                for (int j = 0; j <= l; j++) {
                    if (matrix[row + i][col + j] == '0') {
                        return l;
                    }
                }
            }
        }
        return len;
    }
};
