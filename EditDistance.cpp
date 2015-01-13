class Solution {
    public:
        int minDistance(string word1, string word2) {
            int l1 = word1.size(), l2 = word2.size();
            vector<vector<int> > steps(l1 + 1, vector<int>(l2 + 1, 0));
            int i, j;
            for(i = 0; i <=l2; i++)
                steps[0][i] = i;
            for(i = 0; i <= l1; i++)
                steps[i][0] = i;
            for(i = 0; i < l1; i++) {
                for(j = 0; j < l2; j++) {
                    if(word1[i] == word2[j]) {
                        steps[i + 1][j + 1] = steps[i][j];
                    } else {
                        steps[i + 1][j + 1] = min(
                                steps[i][j],
                                min(steps[i + 1][j],
                                    steps[i][j + 1])) + 1;
                    }
                }
            }
            return steps[l1][l2];
        }
};
