class Solution {
public:
    int maxSubArray(int A[], int n) {
       if(n == 0)
          return 0; 
       int max_sum = A[0];
       for(int i = 1; i < n; i++) {
           if(A[i - 1] >= 0)
               A[i] += A[i - 1];
           if(A[i] > max_sum)
               max_sum = A[i];
       }
       return max_sum;
    }
};
