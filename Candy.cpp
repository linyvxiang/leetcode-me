class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> left_res(ratings.size());
        vector<int> right_res(ratings.size());
        left_res[0] = 1;
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i - 1]) {
                left_res[i] = left_res[i - 1] + 1;
            } else {
                left_res[i] = 1;
            }
        }
        right_res[ratings.size() - 1] = 1;
        for (int i = ratings.size() - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                right_res[i] = right_res[i + 1] + 1;
            } else {
                right_res[i] = 1;
            }
        }
        int ret = 0;
        for (int i = 0; i < ratings.size(); i++) {
            ret += max(left_res[i], right_res[i]);
        }
        return ret;
    }
};
