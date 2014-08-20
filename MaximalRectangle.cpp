class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if(matrix.empty() || matrix[0].empty())
            return 0;
        int row = matrix.size(), column = matrix[0].size();
        vector<vector<int> > height(row, vector<int>(column, 0));
        int i, j;
        for(i = 0; i < row; i++)
            for(j = 0; j < column; j++) {
                if(matrix[i][j] == '0')
                    height[i][j] = 0;
                else {
                    height[i][j] = (i == 0 ? 1 : 1 + height[i - 1][j]);
                }
            }
        int max_area = 0;
        for(i = 0; i < row; i++) 
            max_area = max(max_area, calc_max_area(height[i]));
        return max_area;
    }
private:
    int calc_max_area(vector<int> &height)
    {
        int res = 0, i = 0;
        stack<int> S;
        height.push_back(0);
        while(i < height.size()) {
            if(S.empty() || height[i] > height[S.top()]) {
                S.push(i++);
            } else {
                int t = S.top();
                S.pop();
                res = max(res, height[t] * (S.empty() ? i :
                        (i - S.top() - 1)));
            }
        }
        return res;
    }
};
