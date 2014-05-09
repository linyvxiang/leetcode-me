class Solution {
public:
    void format(string &str)
    {
        string tmp;
        int start =0, end = str.size() - 1;
        while(start < str.size() && str[start] == ' ')
            start++;
        while(end >= 0 && str[end] == ' ')
            end--;
        if(start <= end)
            tmp.insert(tmp.begin(), str.begin() + start, str.begin() + end + 1);
        else
            tmp = "";
        str = tmp;
    }
    void reverseWords(string &s) {
        string res;
        if(s.empty())
            return;
        format(s);
        if(s == "") {
            s.clear();
            return;
        }
        int slow = 0, fast = 0;
        while(slow < s.size()) {
            while(fast < s.size() && s[fast] != ' ')
                fast++;
            res.insert(res.begin(), s.begin() + slow, s.begin() + fast);
            if(fast >= s.size())
                break;
            while(fast < s.size() && s[fast] == ' ')
                fast++;
            slow = fast;
            res.insert(res.begin(), ' ');
        }
        s = res;
        s.erase(s.end() - 1, s.end() - 1);
    }
};
