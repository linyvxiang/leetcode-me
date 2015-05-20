class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) {
            return false;
        }
        if (target < matrix[0][0]) {
            return false;
        }
        int row = matrix.size();
        int col = matrix[0].size();
        int start = 0;
        int end = row - 1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (matrix[mid][0] == target) {
                return true;
            }
            if (matrix[mid][0] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        int possible_row = start - 1;
        start = 0;
        end = col - 1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (matrix[possible_row][mid] == target) {
                return true;
            } else if (matrix[possible_row][mid] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return false;
    }
};
