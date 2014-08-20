class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        int max_area = 0, cur_pos = 0, i;
        stack<int> S;
        height.push_back(0);
        while(cur_pos < height.size()) {
            if(S.empty() || height[cur_pos] > height[S.top()]) {
                S.push(cur_pos++);
            } else {
                int pre = S.top();
                S.pop();
                max_area = max(max_area, height[pre] *
                                (S.empty() ? cur_pos : cur_pos - S.top() - 1));
            }
        }
        return max_area;
    }
};
