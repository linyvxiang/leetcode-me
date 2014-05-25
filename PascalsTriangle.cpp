class Solution {
public:
    vector< vector<int> > generate(int numRows) {
        int i, j;
        vector< vector<int> > res;
        if(numRows == 0)
            return res;
        vector<int> tmp;
        tmp.push_back(1);
        res.push_back(tmp);
        tmp.clear();
        for(i = 1; i < numRows; i++) {
            for(j = 0; j <= i; j++) {
                if(j == 0 || j == i)
                    tmp.push_back(1);
                else
                    tmp.push_back(res[i - 1][j] + res[i - 1][j - 1]);
            }
            res.push_back(tmp);
            tmp.clear();
        }
        return res;
    }
};
