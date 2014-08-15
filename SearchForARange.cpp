class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> res;
        do_search(A, 0, n - 1, target, res);
        if(res.empty()){
            res.push_back(-1);
            res.push_back(-1);
        }
        return res;
    }
private:
    void do_search(int A[], int start_pos, int end_pos, int target, vector<int> &res)
    {
        if(start_pos > end_pos)
            return ;
        int mid = (start_pos + end_pos) >> 1;
        if(A[mid] == target) {
            int left_bound = -1, right_bound;
            find_left_bound(A, start_pos, mid, left_bound, target);
            find_right_bound(A, mid, end_pos, right_bound, target);
            res.push_back(left_bound);
            res.push_back(right_bound);
            return ;
        } else if(A[mid] > target) {
            do_search(A, start_pos, mid - 1, target, res);
        } else {
            do_search(A, mid + 1, end_pos, target, res);
        }
    }
private:
    void find_left_bound(int A[], int start, int end, int &res, int target)
    {
        if(start > end)
            return ;
        int mid = (start + end) >> 1;
        if(A[mid] == target) {
            res = mid;
            find_left_bound(A, start, mid - 1, res, target);
        } else if(A[mid] < target) {
            find_left_bound(A, mid + 1, end, res, target);
        }
    }
    void find_right_bound(int A[], int start, int end, int &res, int target)
    {
        if(start > end)
            return ;
        int mid = (start + end) >> 1;
        if(A[mid] == target) {
            res = mid;
            find_right_bound(A, mid + 1, end, res, target);
        } else if(A[mid] > target) {
            find_right_bound(A, start, mid - 1, res, target);
        }
    }
};
