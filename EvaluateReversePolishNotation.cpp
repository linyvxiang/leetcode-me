class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        int len = tokens.size(), i;
        stack<int> S;
        while(!S.empty())
            S.pop();
        for(i = 0; i < len; i++) {
            if(is_operator(tokens[i])) {
                int num2 = S.top();
                S.pop();
                int num1 = S.top();
                S.pop();
                switch(tokens[i][0]) {
                case '+':
                    S.push(num1 + num2);
                    break;
                case '-':
                    S.push(num1 - num2);
                    break;
                case '*':
                    S.push(num1 * num2);
                    break;
                case '/':
                    S.push(num1 / num2);
                    break;
                }
            } else {
                S.push(trans_num(tokens[i]));
            }
        }
        int res = S.top();
        return res;
    }
private:
    bool is_operator(string &str)
    {
        return (str.size() == 1 && str[0] == '-') ||
                (str.size() == 1 && str[0] == '+') ||
                str[0] == '*' || str[0] == '/';
    }
    int trans_num(string &str)
    {
        int sign = 1, len = str.size(), i = 0, result = 0;
        if(str[0] == '-') {
            sign = -1;
            i++;
        }
        if(str[0] == '+')
            i++;
        for(; i < len; i++) {
            result = result * 10 + str[i] - '0';
        }
        return sign * result;
    }
};
