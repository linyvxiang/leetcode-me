class Solution {
public:
    void format(string &s)
    {
        string res;
        int slow = 0, fast = s.size() - 1;
        while(slow < s.size() && s[slow] == ' ' )
            slow++;
        while(fast >= 0 && s[fast] == ' ' )
            fast--;
        if(slow <= fast)
            res.insert(res.begin(), s.begin() + slow, s.begin() + fast + 1);
        else
            res = "";
        s = res;
    }
    void reverseWords(string &s) {
        if(s.empty())
            return;
        string res;
        format(s);
        if(s == "")
            return ;
        int fast = 0, slow = 0;
        while(slow < s.size()) {
            while(fast < s.size() && s[fast] != ' ')
                fast++;
            res.insert(res.begin(), s.begin() + slow, s.begin() + fast);
            while(fast < s.size() && s[fast] == ' ')
                fast++;
            slow = fast;
            res.insert(res.begin(), ' ');
        }
        s = res;
        s.erase(s.begin(), s.begin() + 1);
    }
};
