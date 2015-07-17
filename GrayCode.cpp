class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ret;
        ret.push_back(0);
        for (int i = 0; i < n; i++) {
            for (int j = ret.size() - 1; j >= 0; j--) {
                ret.push_back(ret[j] | (1 << i));
            }
        }
        return ret;
    }
};
