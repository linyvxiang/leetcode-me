class Solution {
public:
    int mySqrt(int x) {
        int start = 0;
        int end = x / 2 + 1;
        while (start <= end) {
            int mid = (start + end) / 2;
            long long ret = (long long)mid * mid;
            if (ret == x) {
                return mid;
            } else if (ret < x) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return end;
    }
};
