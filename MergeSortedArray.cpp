class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
		int cur_pos = m + n - 1;
		int pos_a = m - 1, pos_b = n - 1;
		while(cur_pos >= 0) {
			if(pos_a >= 0 && pos_b >= 0) {
				if(A[pos_a] > B[pos_b])
					A[cur_pos--] = A[pos_a--];
				else
					A[cur_pos--] = B[pos_b--];
			} else if(pos_a >= 0) {
				break;
			} else {
				A[cur_pos--] = B[pos_b--];
			}
		}
    }
};
