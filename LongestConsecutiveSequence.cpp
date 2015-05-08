class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        if (num.empty()) {
            return 0;
        }
        unordered_map<int, bool> num_map;
        for (int i = 0; i < num.size(); i++) {
            num_map[num[i]] = false;
        }
        unordered_map<int, bool>::iterator it = num_map.begin();
        int max_len = 0;
        for (; it != num_map.end(); ++it) {
            if (it->second == true) {
                continue;
            }
            it->second = true;
            int len = 1;
            for (int cur_num = it->first + 1;
                    num_map.find(cur_num) != num_map.end(); cur_num++) {
                num_map[cur_num] = true;
                len++;
            }
            for (int cur_num = it->first - 1;
                    num_map.find(cur_num) != num_map.end(); cur_num--) {
                num_map[cur_num] = true;
                len++;
            }
            max_len = max(max_len, len);
        }
        return max_len;
    }
};
