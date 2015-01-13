class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> ret;
        if(n == 0) {
            ret.push_back(-1);
            ret.push_back(-1);
            return ret;
        }
        bool flag = false;
        int pos = search_left(A, n, target, flag);
        if(!flag)
            ret.push_back(-1);
        else
            ret.push_back(pos);
        flag = false;
        pos = search_right(A, n, target, flag);
        if(!flag)
            ret.push_back(-1);
        else
            ret.push_back(pos);
        return ret;
    }
private:
    int search_left(int A[], int n, int target, bool &flag)
    {
        int start = 0, end = n - 1;
        while(start <= end) {
            int mid = (start + end) >> 1;
            if(A[mid] >= target) {
                if(A[mid] == target)
                    flag = true;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return start;
    }
    int search_right(int A[], int n, int target, bool &flag)
    {
        int start = 0, end = n - 1;
        while(start <= end) {
            int mid = (start + end) >> 1;
            if(A[mid] <= target) {
                if(A[mid] == target)
                    flag = true;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return end;
    }
};
