class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_map<int, int> hash_map;
        vector<int> res;
        int i;
        for(i = 0; i < numbers.size(); i++)
            hash_map[numbers[i]] = i;
        for(i = 0; i < numbers.size(); i++) {
            int diff = target - numbers[i];
            if(hash_map.find(diff) != hash_map.end() && hash_map[diff] != i) {
                res.push_back(min(i, hash_map[diff]) + 1);
                res.push_back(max(i, hash_map[diff]) + 1);
                break;
            }
        }
        return res;
    }
};
