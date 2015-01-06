class Solution {
    public:
        int sqrt(int x) {
            int start = 0, end = x;
            int ret = -1;
            while(start <= end) {
                int mid = (start + end) >> 1;
                if ((long long)mid * mid == x) {
                    ret = mid;
                    break;
                } else if((long long)mid * mid > x) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }
            if(ret == -1)
                ret = end;
            return ret;
        }
};
