class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if (triangle.size() == 1) {
            return triangle[0][0];
        }
        for (int i = 1; i < triangle.size(); i++) {
            for (int j = 0; j < i + 1; j++) {
                if (j == 0) {
                    triangle[i][j] += triangle[i - 1][j];
                } else if (j == i) {
                    triangle[i][j] += triangle[i - 1][j - 1];
                } else {
                    triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j]);
                }
            }
        };
        int row = triangle.size() - 1;
		int min_sum = triangle[row][0];
        for (int i = 1; i < triangle[row].size(); i++) {
            min_sum = min(min_sum, triangle[row][i]);
        }
        return min_sum;
    }
};
