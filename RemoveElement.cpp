class Solution {
    public:
        int removeElement(int A[], int n, int elem) {
            if(n == 0)
                return 0;
            int count = 0, pre_pos = -1;
            for(int i = 0; i < n; i++)
                if(A[i] == elem)
                    count++;
            for(int i = 0; i < n; i++) {
                if(A[i] != elem)
                    A[++pre_pos] = A[i];
            }
            return pre_pos + 1;
        }
};
