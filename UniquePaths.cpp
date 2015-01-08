#include <vector>
using namespace std;
class Solution {
    public:
        int uniquePaths(int m, int n) {
            vector<vector<int> > matrix(m, vector<int>(n, 0));
            int i, j;
            for(i = 0; i < m; i++) {
                for(j = 0; j < n; j++) {
                    if(i == 0 && j == 0) {
                        matrix[i][j] = 1;
                    } else if(i == 0) {
                        matrix[i][j] = matrix[i][j - 1];
                    } else if(j == 0) {
                        matrix[i][j] = matrix[i - 1][j];
                    } else {
                        matrix[i][j] = matrix[i - 1][j] + matrix[i][j - 1];
                    }
                }
            }
            return matrix[m - 1][n - 1];
        }
};
