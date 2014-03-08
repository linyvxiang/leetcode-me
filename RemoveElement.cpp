class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int final_len = -1;
        if(n == 0)
            return 0;
        int i;
        for(i = 0; i < n; i++)
            if(A[i] != elem)
                A[++final_len] = A[i];
        return final_len + 1;
    }
};
