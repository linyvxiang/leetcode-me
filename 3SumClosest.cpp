class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int ret = 0x0fffffff;
        sort(num.begin(), num.end());
        for(int cur_pos = 0; cur_pos < num.size() - 2; cur_pos++) {
            int start = cur_pos + 1, end = num.size() - 1;
            while(start < end) {
                int t = num[start] + num[end] + num[cur_pos];
                if(abs(t - target) < abs(ret - target))
                    ret = t;
                if(t < target)
                    start++;
                else
                    end--;
            }
        }
        return ret;
    }
};
