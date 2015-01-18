class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > ret;
        if(num.empty() || num.size() < 3)
            return ret;
        sort(num.begin(), num.end());
        int cur_pos = 0;
        while(cur_pos < num.size() - 2) {
            int start = cur_pos + 1, end = num.size() - 1;
            while(start < end) {
                if(num[cur_pos] + num[start] + num[end] == 0) {
                    vector<int> cur_ret;
                    cur_ret.push_back(num[cur_pos]);
                    cur_ret.push_back(num[start]);
                    cur_ret.push_back(num[end]);
                    ret.push_back(cur_ret);
                    start++;
                    end--;
                    while(start < end && num[start] == num[start - 1])
                        start++;
                    while(end > start && num[end] == num[end + 1])
                        end--;
                } else if(num[cur_pos] + num[start] + num[end] < 0) {
                    start++;
                } else {
                    end--;
                }
            }
            cur_pos++;
            while(cur_pos < num.size() - 2 && num[cur_pos] == num[cur_pos - 1])
                cur_pos++;
        }
        return ret;
    }
};
