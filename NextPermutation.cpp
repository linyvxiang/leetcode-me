class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int l = num.size() - 2;
        for(; l >= 0; l--) {
            if(num[l] < num[l + 1]) { //find the left pos
                int r;
                for(r = num.size() - 1; r > l ; r--) {
                    if(num[r] > num[l]) {
                        swap(num[l], num[r]);
                        reverse(num.begin() + l + 1, num.end());
                        return ;
                    }
                }
            }
        }
        reverse(num.begin(), num.end());
        return ;
    }
};
