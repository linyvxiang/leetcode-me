class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int len1 = a.size(), len2 = b.size();
        int i = len1 - 1, j = len2 - 1;
        int flag = 0;
        while(i >= 0 && j >= 0) {
            res.insert(res.begin(), (a[i] - '0' + b[j] - '0' + flag) % 2 + '0');
            flag = (a[i] - '0' + b[j] - '0' + flag) / 2;
            i--;
            j--;
        }
        if(i >= 0) {
            while(i >= 0) {
                res.insert(res.begin(), (a[i] -'0' + flag) % 2 + '0');
                flag = (a[i] - '0' + flag) / 2;
                i--;
            }
        } else if (j >= 0) {
            while (j >= 0) {
                res.insert(res.begin(), (b[j] - '0' + flag) % 2 + '0');
                flag = (b[j] - '0' + flag) / 2;
                j--;
            }
        }
        if(flag)
            res.insert(res.begin(), '1');
        return res;
    }
};
