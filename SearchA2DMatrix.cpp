class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        bool res = false;
        int m = matrix.size(), n = matrix[0].size();
        find(matrix, 0, m * n - 1, target, res);
        return res;
    }
private:
    void find(vector<vector<int> > &matrix, int start, int end, int target, bool &res)
    {
        if(start > end)
            return;
        int mid = (start + end) >> 1;
        int row = mid / matrix[0].size(), column = mid % matrix[0].size();
        if(matrix[row][column] == target) {
            res = true;
            return;
        } else {
            if(matrix[row][column] >  target) {
                find(matrix, start, mid - 1, target, res);
            } else
                find(matrix, mid + 1, end, target, res);
        }
    }
};
