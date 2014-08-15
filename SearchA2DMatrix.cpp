class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int start = 0, end = matrix.size() * matrix[0].size() - 1;
        while(start <= end) {
            int mid = (start + end) >> 1;
            int x = mid / matrix[0].size(), y = mid % matrix[0].size();
            if(matrix[x][y] == target)
                return true;
            if(matrix[x][y] > target)
                end = mid - 1;
            else
                start = mid + 1;
        }
        return false;
    }
};
