class Solution {
public:
    void do_slove(vector<vector<int>> &res, vector<int> cur_res, 
                    vector<int> num, int start, int cur_sum, int target)                                                                
    {
        if(cur_sum == target) {
            res.push_back(cur_res);
            return ;
        }
        if(cur_sum > target)
            return;
        int i, prev = -1;
        for(i = start; i < num.size(); i++) {
            if(num[i] == prev)  continue;
            prev = num[i];
            cur_res.push_back(num[i]);
            do_slove(res, cur_res, num, i + 1, cur_sum + num[i], target);
            cur_res.pop_back();
        }
    }
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int>> res;
        vector<int> cur_res;
        if(num.empty())
            return res;
        sort(num.begin(), num.end());
        do_slove(res, cur_res, num, 0, 0, target);
        return res;
    }
};
