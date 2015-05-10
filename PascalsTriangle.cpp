class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > num;
        for (int i = 0; i < numRows; i++) {
            vector<int> cur_row;
            for (int j = 0; j < i + 1; j++) {
                if (j == 0) {
                    cur_row.push_back(1);
                } else if (j == i) {
                    cur_row.push_back(1);
                } else {
                    cur_row.push_back(num[i - 1][j - 1] + num[i - 1][j]);
                }
            }
            num.push_back(cur_row);
        }
        return num;
    }
};