class Solution {
public:
    int numDistinct(string S, string T) {
        return calc_substr_count(0, 0, 0, S, T);
    }
private:
    int calc_substr_count(int cur_count, int cur_pos_s, int cur_pos_t, 
                            string &S, string &T)
    {
        if(cur_pos_t == T.size())
                return 1;
        if(cur_pos_s >= S.size())
            return 0;
        if(S.size() - cur_pos_s  < T.size() - cur_pos_t)
            return 0;
        int s = cur_pos_s;
        for(; s < S.size(); s++) {
            if(S[s] == T[cur_pos_t])
                return calc_substr_count(cur_count, s + 1, cur_pos_t + 1,
                                            S, T) + 
                        calc_substr_count(cur_count, s + 1, cur_pos_t, S, T);
            else
                return calc_substr_count(cur_count, s + 1, cur_pos_t, S, T);
        }
    }
};
