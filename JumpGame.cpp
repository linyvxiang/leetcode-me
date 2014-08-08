class Solution {
public:
    bool canJump(int A[], int n) {
        if(n == 1)
            return true;
        int max_len = 0, cur_pos;
        for(cur_pos = 0; cur_pos < n; cur_pos++) {
            max_len = max(max_len, cur_pos + A[cur_pos]);
            if(max_len == cur_pos)
                return false;
            if(max_len >= n - 1)
                return true;
        }
    }
};
