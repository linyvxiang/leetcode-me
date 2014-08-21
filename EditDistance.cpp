class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1.size() == 0)
            return word2.size();
        if(word2.size() == 0)
            return word1.size();
        int paths[word1.size() + 1][word2.size() + 1];
        int i, j;
        for(i = 0; i <= word2.size(); i++)
            paths[0][i] = i;
        for(i = 0; i <= word1.size(); i++)
            paths[i][0] = i;
        for(i = 1; i <= word1.size(); i++) {
            for(j = 1; j <= word2.size(); j++) {
                if(word1[i - 1] == word2[j - 1]) {
                      paths[i][j] = paths[i - 1][j - 1];
                } else {
                    paths[i][j] = min(paths[i - 1][j - 1],
                                    min(paths[i][j - 1], paths[i - 1][j])) + 1;
                }
            }
        }
        return paths[word1.size()][word2.size()];
    }
};
