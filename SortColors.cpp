class Solution {
public:
    void sortColors(int A[], int n) {
        int count[3] = {0};
        int i;
        for(i = 0; i < n; i++)
            count[A[i]]++;
        for(i = 0; i < n; i++) {
            if(count[0]) {
                A[i] = 0;
                count[0]--;
            } else if(count[1]) {
                A[i] = 1;
                count[1]--;
            } else {
                A[i] = 2;
                count[2]--;
            }
        }
    }
};
