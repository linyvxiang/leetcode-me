#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Solution {
    public:
        vector<string> restoreIpAddresses(string s) {
            vector<string> ret;
            if(s.empty())
                return ret;
            do_restore(s, ret, 0, "", 0);

            return ret;
        }
    private:
        void do_restore(const string &s, vector<string> &ret,
                            int cur_pos, string cur_part,
                            int cur_part_num)
        {
            if(cur_pos == s.size()) {
                if(cur_part_num == 4) {
                    cur_part.resize(cur_part.size() - 1);
                    ret.push_back(cur_part);
                }
                return ;
            }

            if(s.size() - cur_pos < 4 - cur_part_num)
                return ;
            if(s.size() - cur_pos > 3 * ( 4 - cur_part_num))
                return ;

            string c_s = "";
            int p, cur_num = 0;
            for(p = cur_pos; p < s.size() && p < cur_pos + 3; p++) {
                c_s += s[p];
                cur_num = cur_num * 10 + s[p] - '0';
                if(cur_num == 0) {
                    do_restore(s, ret, p + 1, cur_part + c_s + ".",
                                                    cur_part_num + 1);
                    break;
                } else if(0 < cur_num && cur_num <= 255) {
                    do_restore(s, ret, p + 1, cur_part + c_s + ".",
                                                    cur_part_num + 1);
                }
            }
        }
};


int main()
{
    Solution s;
    string str("11011011");
    vector<string> res;
    res = s.restoreIpAddresses(str);
    int i;
    for(i = 0; i < res.size(); i++)
        cout << res[i] << endl;

    return 0;
}

