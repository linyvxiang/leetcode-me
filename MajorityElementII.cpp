class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0;
        int count2 = 0;
        int num1;
        int num2;
        for (int cur_num : nums) {
            if (count1 == 0 || cur_num == num1) {
                count1++;
                num1 = cur_num;
            } else if (count2 == 0 || cur_num == num2) {
                count2++;
                num2 = cur_num;
            } else {
                count1--;
                count2--;
            }
        }
        count1 = 0;
        count2 = 0;
        for (int cur_num : nums) {
            if (cur_num == num1) {
                count1++;
            } else if (cur_num == num2) {
                count2++;
            }
        }
        vector<int> ret;
        if (count1 > nums.size() / 3) {
            ret.push_back(num1);
        }
        if (count2 > nums.size() / 3) {
            ret.push_back(num2);
        }
        return ret;
    }
};
