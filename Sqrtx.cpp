class Solution {
public:
    int sqrt(int x) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int low = 0, high = x / 2 + 1;
        long long mid, cur_x;
        while(low <= high) {
            mid = (low + high) / 2;
            cur_x = mid * mid;
            if(cur_x == x)
                return mid;
            if(cur_x > x)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return high;
    }
};
