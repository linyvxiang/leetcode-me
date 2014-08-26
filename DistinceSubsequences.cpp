class Solution {
public:
    int numDistinct(string S, string T) {
        int row = S.size(), column = T.size();
        int res[row + 1][column + 1];
        memset(res, 0, sizeof(res));
        int i, j;
        res[0][0] = 1;
        for(i = 1; i <= row; i++)
            res[i][0] = 1;
        for(i = 1; i <= row; i++) {
            for(j = 1; j <= column; j++) {
                if(S[i - 1] != T[j - 1])
                    res[i][j] = res[i - 1][j];
                else
                    res[i][j] = res[i - 1][j] + res[i - 1][j - 1];
            }
        }
        return res[row][column];
    }
};
