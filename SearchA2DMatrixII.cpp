class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return do_search(matrix, 0, 0, target);
    }
private:
    bool find_in_array(vector<vector<int>>& matrix, int row, 
                        int col, int target,  int direc) {
        if (row >= matrix.size() || col >= matrix[0].size()) {
            return false;
        }
        if (direc == 0) { //down 
            int end = matrix.size() - 1;
            int start = row;
            while (start <= end) {
                int mid = (start + end) / 2;
                if (matrix[mid][col] == target) {
                    return true;
                } else if (matrix[mid][col] > target) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }
            return false;
        } else { // right
            int end = matrix[0].size() - 1;
            int start = col;
            while (start <= end) {
                int mid = (start + end) / 2;
                if (matrix[row][mid] == target) {
                    return true;
                } else if (matrix[row][mid] > target) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }
            return false;
        }
    }
    bool do_search(vector<vector<int>>& matrix, int row, int col, int target) {
        if (row >= matrix.size() || col >= matrix[0].size()) {
            return false;
        }
        if (matrix[row][col] == target) {
            return true;
        }
        if (col + 1 >= matrix[0].size()) {
            return find_in_array(matrix, row, col, target, 0);// 0 stands for down
        }
        if (row + 1 >= matrix.size()) {
            return find_in_array(matrix, row, col, target, 1); // 1 stands for right
        }
        if (matrix[row + 1][col] > target && matrix[row][col + 1] > target) {
            return false;
        } else if (matrix[row + 1][col] > target && matrix[row][col] < target) {
            return find_in_array(matrix, row, col, target, 1);
        } else if (matrix[row][col] < target && matrix[row][col + 1] > target) {
            return find_in_array(matrix, row, col, target, 0);
        } else {
            bool ret = find_in_array(matrix, row, col, target, 0);
            if (ret) {
                return ret;
            } else {
                return  do_search(matrix, row, col + 1, target);
            }
        }
    }
};
