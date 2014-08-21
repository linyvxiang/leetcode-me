class Solution {
public:
    string countAndSay(int n) {
        if(n < 1)
            return "";
        string res = "1";
        int i;
        for(i = 2; i <= n; i++)
            res = do_generate(res);
        return res;
    }
private:
    string do_generate(string &res)
    {
        int slow = 0, fast;
        string tmp = "";
        while(slow < res.size()) {
            fast = slow + 1;
            while(fast < res.size() && res[fast] == res[slow])
                fast++;
            tmp += fast - slow + '0';
            tmp += res[slow];
            slow = fast;
        }
        return tmp;
    }
};
