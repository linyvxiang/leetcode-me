class Solution {
    public:
        vector<vector<int> > fourSum(vector<int> &num, int target) {
            vector<vector<int> > ret;
            if(num.empty() || num.size() < 4)
                return ret;
            sort(num.begin(), num.end());
            int first = 0, second;
            while(first < num.size() - 3) {
                second = first + 1;
                while(second < num.size() - 2) {
                    int start = second + 1, end = num.size() - 1;
                    while(start < end) {
                        int t = num[first] + num[second] + num[start] + num[end];
                        if(t == target) {
                            vector<int> cur_ret;
                            cur_ret.push_back(num[first]);
                            cur_ret.push_back(num[second]);
                            cur_ret.push_back(num[start]);
                            cur_ret.push_back(num[end]);
                            ret.push_back(cur_ret);
                            start++;
                            end--;
                            while(start < end && num[start] == num[start - 1])
                                start++;
                            while(end > start && num[end] == num[end + 1])
                                end--;
                        } else if(t > target) {
                            end--;
                        } else {
                            start++;
                        }
                    }
                    second++;
                    while(second < num.size() - 2 && num[second] == num[second - 1])
                        second++;
                }
                first++;
                while(first < num.size() - 3 && num[first] == num[first - 1])
                   first++; 
            }
            return ret;
        }
};
