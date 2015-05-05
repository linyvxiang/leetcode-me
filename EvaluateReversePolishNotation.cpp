class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i][0] >= '0' && tokens[i][0] <= '9'
                    || tokens[i].size() > 1 && tokens[i][0] == '-') {
                int cur_num = atoi(tokens[i].c_str());
                nums.push(cur_num);
            } else {
                int num2 = nums.top();
                nums.pop();
                int num1 = nums.top();
                nums.pop();
                char op = tokens[i][0];
                switch (op) {
                    case '+' :
                        nums.push(num1 + num2);
                        break;
                    case '-' :
                        nums.push(num1 - num2);
                        break;
                    case '*' :
                        nums.push(num1 * num2);
                        break;
                    case '/' :
                        nums.push(num1 / num2);
                        break;
                }
            }
        }
        return nums.top();
    }
};
