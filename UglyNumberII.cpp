class Solution {
public:
    int nthUglyNumber(int n) {
        set<long long> nums;
        nums.insert(1);
        while (--n) {
            long long cur_num = *nums.begin();
            nums.erase(cur_num);
            nums.insert(cur_num * 2);
            nums.insert(cur_num * 3);
            nums.insert(cur_num * 5);
        }
        return *nums.begin();
    }
};
