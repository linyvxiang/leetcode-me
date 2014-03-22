class Solution {
public:
    int singleNumber(int A[], int n) {
        int L = sizeof(int) * 8;
        int count[L], i, j;
        for(i = 0; i < L; i++)
            count[i] = 0;
        for(i = 0; i < n; i++) {
            for(j = 0; j < L; j++) {
                int tmp = A[i] >> j & 1;
                if(tmp)
                    count[j]++;
            }
        }
        int res = 0;
        for(i = 0; i < L; i++)
            if(count[i] % 3 != 0) 
                res |= 1 << i;
        return res;
    }
};
