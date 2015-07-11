class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }
        vector<vector<int>> max_len(matrix.size(), vector<int>(matrix[0].size(), 0));
        int len = 0;
        for (int i = 0; i < matrix[0].size(); i++) {
            if (matrix[0][i] == '1') {
                max_len[0][i] = 1;
            } else {
                max_len[0][i] = 0;
            }
            len = max(len, max_len[0][i]);
        }
        for (int i = 0; i < matrix.size(); i++) {
            if (matrix[i][0] == '1') {
                max_len[i][0] = 1;
            } else {
                max_len[i][0] = 0;
            }
        }
        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 1; j < matrix[0].size(); j++) {
                if (matrix[i][j] == '0') {
                    max_len[i][j] = 0;
                } else {
                    /*
                    if (matrix[i][j - 1] == '1' && matrix[i - 1][j] == '1') {
                        max_len[i][j] = max_len[i - 1][j - 1] + 1;
                    } else {
                        max_len[i][j] = 1;
                    }
                    above is wrong in the following case:
                    0 0 0 1
                    1 1 0 1
                    1 1 1 1
                    0 1 1 1
                    0 1 1 1
                    */
                    max_len[i][j] = min(max_len[i - 1][j - 1],
                            min(max_len[i][j - 1], max_len[i - 1][j])) + 1;
                }
                len = max(len, max_len[i][j]);
            }
        }
        return len * len;
    }
};
