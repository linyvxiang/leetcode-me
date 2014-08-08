class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > fin_res;
        if(num.empty() || num.size() < 3)
            return fin_res;
        int cur_pos = 0;
        sort(num.begin(), num.end());
        while(cur_pos < num.size() - 2) {
            int low = cur_pos + 1, high = num.size() - 1;
            while(low < high) {
                if(num[low] + num[high] + num[cur_pos] == 0) { 
                    vector<int> tmp_res;
                    tmp_res.push_back(num[cur_pos]);
                    tmp_res.push_back(num[low]);
                    tmp_res.push_back(num[high]);
                    fin_res.push_back(tmp_res);
                    low++;
                    high--;
                    while(low < high && num[low] == num[low - 1])
                        low++;
                    while(high > low && num[high] == num[high + 1])
                        high--;
                } else if(num[low] + num[high] + num[cur_pos] > 0) {
                    high--;
                } else {
                    low++;
                }
            }
            cur_pos++;
            while(cur_pos < num.size() - 2 && num[cur_pos] == num[cur_pos - 1])
                cur_pos++;
        }
        return  fin_res;
    }
};
