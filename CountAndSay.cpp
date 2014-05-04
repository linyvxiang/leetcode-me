class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        n--;
        while(n--) {
            int fast = 0 , slow = 0;
            string temp;
            while(fast < res.size()) {
                while(fast < res.size() && res[fast] == res[slow])
                    fast++;
                temp.insert(temp.end(), fast - slow + '0');
                temp.insert(temp.end(), res[slow]);
                slow = fast;
                if(fast >= res.size())
                  break;
            }
            res = temp;
        }
        return res;
    }
};
