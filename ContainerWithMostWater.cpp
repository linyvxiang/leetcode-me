class Solution {
public:
    int maxArea(vector<int> &height) {
        int start = 0, end = height.size() - 1;
        int max_area = 0;
        while(start < end) {
            int cur_area = (end - start) * min(height[start], height[end]);
            max_area = max(cur_area, max_area);
            if(height[start] < height[end])
                start++;
            else
                end--;
        }
        return max_area;
    }
};
