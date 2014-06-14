class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > res;
        vector<int> tmp;
        generate_combines(1, 0, n, k, tmp, res);
        return res;
    }
private:
    void generate_combines(int cur_pos, int numbers, int n, int k,
                            vector<int> &tmp, vector<vector<int> > &res)
    {

        if(numbers == k) {
            res.push_back(tmp);
        }
        int start = cur_pos;
        for(start = cur_pos; start <= n; start++) {
            tmp.push_back(start);
            generate_combines(start + 1, numbers + 1, n, k, tmp, res);
            tmp.pop_back();
        }
    }    
};
