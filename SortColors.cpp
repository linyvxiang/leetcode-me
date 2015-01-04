#include <iostream>
using namespace std;
class Solution {
public:
    void sortColors(int A[], int n) {
        if(n == 0)
            return ;
        int back_pos = -1, front_pos = n, cur_pos = 0;
        while(cur_pos < n) {
            if(cur_pos >= front_pos)
                break;
            if(A[cur_pos] == 0 && cur_pos > back_pos)
                swap(A[++back_pos], A[cur_pos]);
            else if(A[cur_pos] == 2 && cur_pos < front_pos)
                swap(A[--front_pos], A[cur_pos]);
            else
                cur_pos++;
        }
    }
};

int main()
{
    int A[] = { 2, 1, 2, 1, 1, 0};
    Solution s;
    s.sortColors(A, 6);
    int i;
    for(i = 0; i < 6; i++)
        cout << A[i] << " ";
    cout << endl;
    return 0;
}

