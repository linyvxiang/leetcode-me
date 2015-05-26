class Solution {
public:
    bool isValid(string s) {
        if (s.empty()) {
            return true;
        }
        stack<int> S;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                S.push(i);
            } else {
                if (S.empty()) {
                    return false;
                }
                if (s[i] == ')') {
                    if (s[S.top()] == '(') {
                        S.pop();
                    } else {
                        return false;
                    }
                } else if (s[i] == ']') {
                    if (s[S.top()] == '[') {
                        S.pop();
                    } else {
                        return false;
                    }
                } else if (s[i] == '}') {
                    if (s[S.top()] == '{') {
                        S.pop();
                    } else {
                        return false;
                    }
                } else {
                    return false;
                }
            }
        }
        return S.empty();
    }
};
