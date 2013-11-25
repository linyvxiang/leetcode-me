class Solution {
public:
    int find_first(int num_array[], int start_pos, int end_pos, int target)
    {
        if(start_pos > end_pos)
            return -1;
        int i;
        for(i = start_pos; i < end_pos; i++)
            if(num_array[i] != target)
                return i;
        return -1;
    }
    void do_move(int num_array[], int back_pos, int front_pos, int end)
    {
        int i;
        for(i = 0; i < end - front_pos + 1; i++)
            num_array[back_pos + i] = num_array[front_pos + i];
    }
    int removeDuplicates(int A[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(!n)
            return n;
        int cur_pos = 0, moved = 0, first_pos;
        while(cur_pos < n - moved) {
            first_pos = find_first(A, cur_pos + 1, n - moved, A[cur_pos]);
            if(first_pos != -1) {
            do_move(A, cur_pos + 1, first_pos, n - moved);
            moved += first_pos - cur_pos - 1;
            } else {
                int this_len = n - moved - cur_pos - 1;
                moved += this_len;
                break;
            }
            cur_pos++;
        }
        return n - moved;
    }
};
