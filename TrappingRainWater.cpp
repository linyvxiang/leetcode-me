class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) {
            return 0;
        }
        vector<int> left_max(height.size(), 0);
        vector<int> right_max(height.size(), 0);
        for (int i = 0; i < height.size(); i++) {
            if (i == 0) {
                left_max[i] = height[0];
            } else {
                left_max[i] = max(left_max[i - 1], height[i]);
            }
        }
        for (int i = height.size() - 1; i >= 0; i--) {
            if (i == height.size() - 1) {
                right_max[i] = height[height.size() - 1];
            } else {
                right_max[i] = max(right_max[i + 1], height[i]);
            }
        }
        int max_area = 0;
        for (int i = 0; i < height.size(); i++) {
            max_area += min(left_max[i], right_max[i]) - height[i];
        }
        return max_area;
    }
};
