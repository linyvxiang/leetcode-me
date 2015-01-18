class Solution {
public:
    bool isValid(string s) {
        if(s.empty())
            return true;
        stack<char> S;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(' || s[i] == '['
                    || s[i] == '{')
                S.push(s[i]);
            else if(s[i] == ')' && !S.empty() && S.top() == '(' ||
                    s[i] == ']' && !S.empty() && S.top() == '[' ||
                    s[i] == '}' && !S.empty() && S.top() == '{')
                S.pop();
            else
                return false;
        }
        return S.empty();
    }
};
