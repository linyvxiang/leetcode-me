class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int cur_end_all = m + n - 1, cur_a = m - 1, cur_b = n - 1;
        while(cur_end_all >= 0) {
            if(cur_a >= 0 && cur_b >= 0) {
                if(A[cur_a] > B[cur_b]) { //move A[cur_a] to the final pos
                    A[cur_end_all] = A[cur_a];
                    cur_a--;
                    cur_end_all--;
                } else {
                    A[cur_end_all] = B[cur_b];
                    cur_b--;
                    cur_end_all--;
                }
            } else {
                if(cur_a >= 0) {
                    A[cur_end_all] = A[cur_a];
                    cur_a--;
                    cur_end_all--;
                } else {
                    A[cur_end_all] = B[cur_b];
                    cur_b--;
                    cur_end_all--;
                }
            }
        }
    }
};
