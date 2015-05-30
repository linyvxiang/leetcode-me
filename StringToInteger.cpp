class Solution {
public:
    int myAtoi(string str) {
        long long ret = atoll(str.c_str());
        if (ret > INT_MAX) {
            ret = INT_MAX;
        } else if (ret < INT_MIN) {
            ret = INT_MIN;
        }
        return (int)ret;
    }
};
