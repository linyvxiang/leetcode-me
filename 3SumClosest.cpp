class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int res = 0x0fffffff, cur_pos = 0;
        sort(num.begin(), num.end());
        while(cur_pos < num.size() - 2) {
            int low = cur_pos + 1, high = num.size() - 1;
            while(low < high) {
                int cur_diff = num[cur_pos] + num[low] + num[high];
                if(abs(cur_diff - target) < abs(res - target))
                    res = cur_diff;
                if(cur_diff == target) {
                    return target;
                } else if(cur_diff > target) {
                    high--;
                } else {
                    low++;
                }
            }
            cur_pos++;
        }
        return res;
    }
};
