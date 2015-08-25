class Solution {
public:
    int nthUglyNumber(int n) {
        vector<long long> nums;
        int id2 = 0;
        int id3 = 0;
        int id5 = 0;
        int ret = 1;
        while (--n) {
            nums.push_back(ret);
            int v2 = nums[id2] * 2;
            int v3 = nums[id3] * 3;
            int v5 = nums[id5] * 5;
            ret = min(v2, min(v3, v5));
            id2 += (ret == v2);
            id3 += (ret == v3);
            id5 += (ret == v5);
        }
        return ret;
    }
};
