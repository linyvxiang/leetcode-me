class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        vector<int> res;
        if(digits.empty())
            return res;
        int i, n = digits.size(), flag = 1;
        for(i = n - 1; i >= 0; i--) {
            int tmp = flag + digits[i];
            flag = tmp / 10;
            res.insert(res.begin(), tmp % 10);
        }
        if(flag)
            res.insert(res.begin(), flag);
        return res;
    }
};
