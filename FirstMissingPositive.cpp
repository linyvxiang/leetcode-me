class Solution {
    public:
        int firstMissingPositive(int A[], int n) {
            if(n == 0)
                return 1;
            int cur_pos = 0;
            while(cur_pos < n) {
                if(A[cur_pos] != cur_pos + 1 && 
                        A[cur_pos]- 1 >= 0
                        && A[cur_pos] - 1 < n &&
                        A[A[cur_pos] - 1] != A[cur_pos])
                    swap(A[cur_pos], A[A[cur_pos] - 1]);
                else
                    cur_pos++;
            }
            for(cur_pos = 0; cur_pos < n; cur_pos++)
                if(A[cur_pos] != cur_pos + 1)
                    return cur_pos + 1;
            return n + 1;
        }
};
