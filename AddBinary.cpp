#include <string>
using namespace std;
class Solution {
    public:
        string addBinary(string a, string b) {
            string str;
            int flag = 0, l1 = a.size() - 1, l2 = b.size() - 1;
            while(l1 >= 0 && l2 >= 0) {
                int tmp = (a[l1] - '0' + b[l2] - '0' + flag) % 2;
                str.insert(str.end(), tmp + '0');
                flag = (a[l1] - '0' + b[l2] - '0' + flag) / 2;
                l1--;
                l2--;
            }
            if(l1 >= 0) {
                while(l1 >= 0) {
                    int tmp = (a[l1] - '0' + flag) % 2;
                    str.insert(str.end(), tmp + '0');
                    flag = (a[l1] - '0' + flag) / 2;
                    l1--;
                }
            } else {
                while(l2 >= 0) {
                    int tmp = (b[l2] - '0' + flag) % 2;
                    str.insert(str.end(), tmp + '0');
                    flag = (b[l2] - '0' + flag) / 2;
                    l2--;
                }
            }
            if(flag)
                str.insert(str.end(), '1');
            std::reverse(str.begin(), str.end());
            return str;
        }
};
