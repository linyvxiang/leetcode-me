class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length(), i;
        if(!n)
            return 0;
        string t = "^";
        for(i = 0; i < n; i++)
            t += "#" + s.substr(i, 1);
        t += "#$";
        int C = 0, R = 0;
        n = t.length();
        int P[n];
        memset(P, 0, sizeof(P));
        for(i = 1; i < n - 1; i++) {
            int i_mirror = C - (i - C);
            P[i] = R > i ? min(R - i, P[i_mirror]) : 0;
            
            while(t[i + P[i] + 1] == t[i - P[i] - 1])
                P[i]++;

            if(P[i] + i > R) {
                C = i;
                R = P[i] + i;
            }
        }
        int maxlen = 0, index = 0;
        for(i = 1; i < n - 1; i++) {
            if(P[i] > maxlen) {
                maxlen = P[i];
                index = i;
            }
        }
        return s.substr((index - 1 - maxlen) / 2, maxlen);
    }
};
