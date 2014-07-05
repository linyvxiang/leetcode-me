#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <math.h>
#include <time.h>
#include <stack>
#include <vector>
#include <string>
#include <sys/wait.h>
#include <string>
#include <unordered_set>
#include <iterator>
#include <vector>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string> &dict) {
        return do_judge(0, s, dict);
    }
private:
    bool do_judge(int cur_pos, const string& s, const vector<string> &dict)
    {
        if(cur_pos >= s.size())
            return true;
        int i, len = s.size();
        for(i = 0; i < dict.size(); i++) {
            if(cur_pos + dict[i].size() > len)
                continue;
            if(check(cur_pos, s, dict[i])) {
                bool temp =  do_judge(cur_pos + dict[i].size(), s, dict);
                if(temp)
                    return true;
            }
        }
        return false;
   }
   bool check(int cur_pos, const string &s, const string &tem)
   {
       int i;
       for(i = 0; i < tem.size(); i++)
            if(s[cur_pos + i] != tem[i])
                return false;

       return true;
   }
};

int main()
{
    Solution s;
    vector<string> dict;
    dict.push_back("a");
    dict.push_back("b");
    bool res;
    res = s.wordBreak("ababaabba", dict);
    if(res)
        printf("yes\n");
    else
        printf("no\n");
    return 0;
}
