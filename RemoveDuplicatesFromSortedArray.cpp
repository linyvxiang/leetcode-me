class Solution {
    public:
        int removeDuplicates(int A[], int n) {
            if(n == 0)
                return 0;
            int cur_pos = 0, pre_pos = -1, next_pos;
            while(cur_pos < n) {
                next_pos = cur_pos;
                while(next_pos < n  && A[next_pos] == A[cur_pos])
                    next_pos++;
                A[++pre_pos] = A[cur_pos];
                cur_pos = next_pos;
            }
            return pre_pos + 1;
        }
};
