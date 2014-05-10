class Solution {
public:
    bool isValid(string s) {
        stack<char> S;
        int i;
        for(i = 0; i < s.size(); i++) {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
                S.push(s[i]);
                continue;
            }
            if(S.empty())
                return false;
            else if(s[i] == ')' && S.top() != '(')
                return false;
            else if(s[i] == ']' && S.top() != '[')
                return false;
            else if(s[i] == '}' && S.top() != '{')
                return false;
            S.pop();
        }
        return S.empty();
    }
};
