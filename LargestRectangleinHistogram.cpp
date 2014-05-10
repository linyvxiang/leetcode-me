class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        int i;
        stack<int> S;
        height.push_back(0);
        int result = 0;
        for(i = 0; i < height.size();) {
            if(S.empty() || height[S.top()] < height[i])
                S.push(i++);
            else {
                int temp = S.top();
                S.pop();
                result = max(result,
                            height[temp] * (S.empty() ? i : i - S.top() - 1));
            }
        }
        return result;
    }
};
