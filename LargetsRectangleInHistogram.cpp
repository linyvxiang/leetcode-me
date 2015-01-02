class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        height.push_back(0);
        int max_rect = 0, cur_pos = 0;
        stack<int> s;
        while(cur_pos < height.size()) {
            if(s.empty() || height[s.top()] < height[cur_pos]) {
                s.push(cur_pos++);
            } else {
                int h = s.top();
                s.pop();
                max_rect = max(max_rect, height[h] * (
                            s.empty() ? cur_pos : cur_pos - s.top() - 1));
            }
        }
        return max_rect;
    }
};
