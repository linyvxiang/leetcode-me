class Solution {
    public:
        int maximalRectangle(vector<vector<char> > &matrix) {
            if(matrix.empty())
                return 0;
            vector<vector<int> > num(matrix.size(), 
                    vector<int>(matrix[0].size(), 0));
            int i, j;
            for(i = 0; i < matrix.size(); i++) {
                for(j = 0; j < matrix[i].size(); j++) {
                    if(matrix[i][j] == '0') {
                        num[i][j] = 0;
                    } else {
                        num[i][j] = (i == 0 ? 1 : 1 + num[i - 1][j]);
                    }
                }
            }
            int max_area = 0;
            for(i = 0; i < matrix.size(); i++)
                max_area = max(max_area, calc_rect(num[i]));
            return max_area;
        }
    private:
        int calc_rect(vector<int> &m)
        {
            stack<int> s;
            int cur_pos = 0, ret = 0;
            m.push_back(0);
            while(cur_pos < m.size()) {
                if(s.empty() || m[s.top()] <= m[cur_pos]) {
                    s.push(cur_pos++);
                } else {
                    int h = s.top();
                    s.pop();
                    ret = max(ret, m[h] * (s.empty() ?
                                cur_pos : cur_pos - s.top() - 1));
                }
            }
            return ret;
        }
};
