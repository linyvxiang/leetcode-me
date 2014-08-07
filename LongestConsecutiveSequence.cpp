class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        if(num.size() == 0)
            return 0;
        unordered_map<int, bool> used;
        for(auto i : num)
            used[i] = false;
        int max_len = 0;
        for(auto i : num) {            
            if(used[i])
                continue;              
    
            int length = 1;
            used[i] = true;
            for(int j = i + 1; used.find(j) != used.end(); j++) {
                used[j] = true;
                length++;
            }
            for(int j = i - 1; used.find(j) != used.end(); j--) {
                used[j] = true;
                length++;
            }

            max_len = max(length, max_len);
        }
        return max_len;
    }
};
