class Solution {
    public:
        bool searchMatrix(vector<vector<int> > &matrix, int target) {
            int row = matrix.size(), column = matrix[0].size();
            int start = 0, end = row - 1;
            int mid;
            if(target < matrix[0][0] || target > matrix[row - 1][column - 1])
                return false;
            while(start <= end) {
                mid = (start + end) >> 1;
                if(matrix[mid][0] == target)
                    return true;
                if(matrix[mid][0] < target)
                    start = mid + 1;
                else if(matrix[mid][0] > target)
                    end = mid - 1;
            }
            mid = end;
            start = 0;
            end = column - 1;
            while(start <= end) {
                int m = (start + end) >> 1;
                if(matrix[mid][m] == target)
                    return true;
                if(matrix[mid][m] > target)
                    end = m - 1;
                else
                    start = m + 1;
            }
            return false;
        }
};
