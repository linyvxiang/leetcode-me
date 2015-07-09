class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        for (string cur_num : tokens) {
            if ((cur_num.size() > 1 && 
                (cur_num[0] == '-' || cur_num[0] == '+')) ||
                    (cur_num[0] >= '0' && cur_num[0] <= '9')) {
                nums.push(atoi(cur_num.c_str()));
            } else {
                int num2 = nums.top();
                nums.pop();
                int num1 = nums.top();
                nums.pop();
                if (cur_num == "+") {
                    nums.push(num1 + num2);
                } else if (cur_num == "-") {
                    nums.push(num1 - num2);
                } else if (cur_num == "*") {
                    nums.push(num1 * num2);
                } else if (cur_num == "/") {
                    nums.push(num1 / num2);
                }
            }
        }
        return nums.top();
    }
};
