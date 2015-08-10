class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cur_pos = 0;
        int ret = 0;
        while (cur_pos < 32) {
            ret += n & 0x1;
            n >>= 1;
            cur_pos++;
        }
        return ret;
    }
};

