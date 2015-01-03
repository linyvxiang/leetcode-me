class Solution {
    public:
        int removeDuplicates(int A[], int n) {
           int cur_pos = 0, front_pos = 0, write_pos = 0;
            while(cur_pos < n) {
                front_pos = cur_pos;
                while(front_pos < n &&
                        A[front_pos] == A[cur_pos])
                    front_pos++;
                if(front_pos - cur_pos > 1) {
                    A[write_pos] = A[cur_pos];
                    A[write_pos + 1] = A[cur_pos];
                    write_pos += 2;
                    cur_pos = front_pos;
                } else {
                    int num = front_pos - cur_pos;
                    while(num--) {
                        A[write_pos + num] = A[cur_pos];
                    }
                    write_pos += front_pos - cur_pos;
                    cur_pos = front_pos;
                }
            }
            return write_pos;
        }
};
