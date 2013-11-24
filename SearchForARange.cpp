class Solution {
public:
    int find_pos(int A[], int n, int target)
    {
        int low = 0, high = n;
        int mid;
        while(low <= high) {
            mid = (low + high) >> 1;
            if(A[mid] == target)
                return mid;
            if(A[mid] > target)
                high = mid -1;
            else
                low = mid + 1;
        }
        return -1;
    }
    vector<int> searchRange(int A[], int n, int target) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int pos = find_pos(A, n, target);
        int left = pos, right = pos;
        vector<int> V;
        if(pos == -1) {
            V.push_back(-1);
            V.push_back(-1);
            return move(V);
        }
        while(A[left] == target && left >= 0)
            left--;
        while(A[right] == target && right < n)
            right++;
        V.push_back(left + 1);
        V.push_back(right - 1);
        return move(V);
    }
};
