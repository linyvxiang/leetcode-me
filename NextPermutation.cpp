class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int pn_pos = num.size() - 2, cn_pos;
        for(; pn_pos >= 0; pn_pos--) {
            if(num[pn_pos] < num[pn_pos + 1]) {
                for(cn_pos = num.size() - 1; cn_pos >= 0; cn_pos--) {
                    if(num[cn_pos] > num[pn_pos]) {
                        swap(num[pn_pos], num[cn_pos]);
                        reverse(num.begin() + pn_pos + 1, num.end());
                        return ;
                    }
                }
            }
        }
        reverse(num.begin(), num.end());
        return ;
    }
};
