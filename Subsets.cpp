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
    void generate_subsets(vector<int> &S, int cur_pos, vector<int> &tmp, vector<vector<int> > &res)
    {
        if(cur_pos == S.size()) {
            res.push_back(tmp);
            return;
        }
        tmp.push_back(S[cur_pos]);
        generate_subsets(S, cur_pos + 1, tmp, res);
        tmp.pop_back();
        generate_subsets(S, cur_pos + 1, tmp, res);
    }
};
