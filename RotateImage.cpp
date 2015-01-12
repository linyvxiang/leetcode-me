#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        for(int i = 0; i < matrix.size(); i++)
            for(int j = 0; j < i; j++) {
                int tmp = matrix[j][i];
                matrix[j][i] = matrix[i][j];
                matrix[i][j] = tmp;
            }
        for(int i = 0; i < matrix.size(); i++)
            for(int j = 0; j < matrix.size() / 2; j++) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[i][matrix.size() - 1 - j];
                matrix[i][matrix.size() - 1 - j] = tmp;
                //swap(matrix[i][j], matrix[i][matrix.size() - 1 - j]);
            }
    }
};

int main()
{
    vector<vector<int> > nums(3, vector<int>(3, 0));
    for(int i = 0;  i < 3; i++)
        for(int j = 0; j < 3; j++)
            nums[i][j] = i * 3 + j;
    Solution s;
    s.rotate(nums);
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++)
            cout << nums[i][j] << " ";
        cout << endl;
    }
    return 0;
}
