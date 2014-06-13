class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > res;
        vector<int> tmp;
        sort(S.begin(), S.end());
        generate_subsets(S, 0, tmp, res);
        return res;
    }
private:
    void generate_subsets(vector<int> &S, int cur_pos, vector<int> &tmp, vector<vector<int>> &res)
    {
        res.push_back(tmp);
        int start;
        for(start = cur_pos; start < S.size(); start++) {
            tmp.push_back(S[start]);
            generate_subsets(S, start + 1, tmp, res);
            tmp.pop_back();
        }
    }
};
