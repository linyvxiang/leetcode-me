class Solution {
public:
    static bool cmp(const string& str1, const string& str2) {
        return str1 + str2 > str2 + str1;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> num_str;
        for (int i = 0; i < nums.size(); i++) {
            num_str.push_back(itoa(nums[i]));
        }
        sort(num_str.begin(), num_str.end(), cmp);
        string ret;
        for (int i = 0; i < num_str.size(); i++) {
            ret += num_str[i];
        }
        if (ret[0] == '0') {
            return "0";
        } else {
            return ret;
        }
    }
private:
    string itoa(int num) {
        if (num == 0) {
            return "0";
        }
        string ret;
        while (num) {
            ret += num % 10 + '0';
            num /= 10;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
