class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int pos_l = num.size() - 2, pos_r;
        for(; pos_l >= 0; pos_l--) {
            if(num[pos_l] < num[pos_l + 1]) {
                for(pos_r = num.size() -1; pos_r >= 0; pos_r--) {
                    if(num[pos_r] > num[pos_l]) {
                        swap(num[pos_l], num[pos_r]);
                        reverse(num.begin() + pos_l + 1, num.end());
                        return ;
                    }
                }
            }
        }
        reverse(num.begin(), num.end());
        return ;
    }
};
