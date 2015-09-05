class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return do_search(matrix, 0, matrix[0].size() - 1, target);
    }
private:
    bool do_search(vector<vector<int>>& matrix, int x, int y, int target) {
        if (x >= matrix.size() || y < 0) {
            return false;
        }
        if (matrix[x][y] == target) {
            return true;
        } else if (matrix[x][y] < target) {
            return do_search(matrix, x + 1, y, target);
        } else {
            return do_search(matrix, x, y - 1, target);
        }
    }
};
