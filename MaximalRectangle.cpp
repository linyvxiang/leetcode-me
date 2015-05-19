class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }
        vector<int> height(matrix[0].size() + 1, 0);
        int max_area = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (i == 0) {
                    if (matrix[i][j] == '0') {
                        height[j] = 0;
                    } else {
                        height[j] = 1;
                    }
                } else {
                    if (matrix[i][j] == '1') {
                        height[j] += 1;
                    } else {
                        height[j] = 0;
                    }
                }
            }
            max_area = max(max_area, calc_max_area(height));
        }
        return max_area;
    }
private:
    int calc_max_area(const vector<int>& height) {
        stack<int> S;
        int cur_pos = 0;
        int max_area = 0;
        while (cur_pos < height.size()) {
            if (S.empty() || height[cur_pos] > height[S.top()]) {
                S.push(cur_pos++);
            } else {
                int h = height[S.top()];
                S.pop();
                max_area = max(max_area, h * (
                            S.empty() ? cur_pos : cur_pos - S.top() - 1));
            }
        }
        return max_area;
    }
};
