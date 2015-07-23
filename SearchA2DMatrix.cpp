class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) {
            return false;
        }
        int start = 0;
        int end = matrix.size() - 1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (matrix[mid][0] == target) {
                return true;
            } else if (matrix[mid][0] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        if (end < 0) {
            return false;
        }
        return binary_search(matrix, end, target);
    }
private:
    bool binary_search(vector<vector<int>>& matrix, int row, int target) {
        int start = 0;
        int end = matrix[row].size() - 1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (matrix[row][mid] == target) {
                return true;
            } else if (matrix[row][mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return false;
    }
};
