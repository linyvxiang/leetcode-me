class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        vector<int> sum(nums.size() + 1, 0);
        for (int i = 1; i < sum.size(); i++) {
            sum[i] = sum[i - 1] + nums[i - 1];
        }
        int min_len = INT_MAX;
        for (int i = 0; i < sum.size(); i++) {
            int lower_bound = find_lower_bound(sum, i + 1, sum.size() - 1, s + sum[i]);
            if (lower_bound == sum.size()) {
                break;
            }
            min_len = min(min_len, lower_bound - i);
        }
        return min_len == INT_MAX ? 0 : min_len;
    }
private:
    int find_lower_bound(vector<int>& num, int start, int end, int target) {
        while (start <= end) {
            int mid = (start + end) / 2;
            if (num[mid] >= target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return start;
    }
};
