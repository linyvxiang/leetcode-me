class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<int> tmp;
        vector<vector<int> > res;
        sort(S.begin(), S.end());
        generate_subsets(S, 0, tmp, res);
        return res;
    }
private:
    void generate_subsets(vector<int> &S, int cur_pos, vector<int> &tmp, 
                                            vector<vector<int> > &res)
    {
        res.push_back(tmp); 

        int start;
        for(start = cur_pos; start < S.size(); start++) {
            if(start != cur_pos && S[start] == S[start - 1])
                continue;
            tmp.push_back(S[start]);
            generate_subsets(S, start + 1, tmp, res);
            tmp.pop_back();
        }
    }
};
