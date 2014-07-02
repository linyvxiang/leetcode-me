class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size(), len2 = word2.size();
        int res[len1 + 1][len2 + 1];
        int i, j;
        for(i = 0; i <= len1; i++)
            res[i][0] = i;
        for(j = 0; j <= len2; j++)
            res[0][j] = j;
        for(i = 1; i <= len1; i++)
            for(j = 1; j<= len2; j++) {
                if(word1[i - 1] == word2[j - 1])
                    res[i][j] = res[i - 1][j - 1];
                else {
                    res[i][j] = min(res[i - 1][j] + 1, res[i][j - 1] + 1,
                                    res[i - 1][j - 1] + 1);
                }
            }
        return res[len1][len2];
    }
private:
    int min(int a, int b, int c)
    {
        int res = a;
        int ano = b < c ? b : c;
        return res < ano ? res : ano;
    }
      
};
