class Solution {
public:
    int sqrt(int x) {
        if(x < 2)
            return x;
        int low = 1, high = x / 2;
        while(low <= high) {
            int mid = (low + high) >> 1;
            if(x / mid == mid)
                return mid;
            if(x / mid > mid)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return high;
    }
};
