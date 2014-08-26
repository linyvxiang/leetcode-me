class Solution {
public:
    int numDistinct(string S, string T) {
        int row = S.size(), column = T.size();
        vector<int> res(column + 1, 0);
        res[0] = 1;
        int i, j;
        for(i = 1; i <= row; i++)
            for(j = column; j >= 1; j--)
                if(S[i - 1] == T[j - 1])
                    res[j] = res[j - 1] + res[j];
        return res[column];
    }
};
