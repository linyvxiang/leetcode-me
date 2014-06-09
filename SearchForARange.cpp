class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int left_bound = -1, right_bound = -1;
        find_bound(A, 0, n - 1, target, left_bound, 0);
        find_bound(A, 0, n - 1, target, right_bound, 1);
        vector<int> res;
        if(left_bound > right_bound)
            swap(left_bound, right_bound);
        res.push_back(left_bound);
        res.push_back(right_bound);
        return res;
    }
private:
    void find_bound(int A[], int start, int end, int target, int &bound, int direc)
    {
        if(start > end)
            return;
        int mid = (start + end) >> 1;
        if(A[mid] == target) {
            bound = mid;
            if(direc == 0)
                find_bound(A, mid + 1, end, target, bound, direc);
            else
                find_bound(A, start, mid - 1, target, bound, direc);
        } else {
            if(A[mid] > target)
                find_bound(A, start, mid - 1, target, bound, direc);
            else 
                find_bound(A, mid + 1, end, target, bound, direc);
        }
    }
};
