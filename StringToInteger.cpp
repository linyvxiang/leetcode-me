class Solution {
    public:
        int atoi(const char *str) {
            if(str == NULL)
                return 0;
            int cur_pos = 0;
            int flag = 1;
            long long ret = 0;
            while(str[cur_pos] == ' ') {
                cur_pos++;
            }
            if(str[cur_pos] == '-') {
                flag = -1;
                cur_pos++;
            } else if(str[cur_pos] == '+') {
                cur_pos++;
            }
            while(str[cur_pos]) {
                if(!('0' <= str[cur_pos] && str[cur_pos] <= '9'))
                    break;
                if(ret * 10 + str[cur_pos] -'0' < ret)
                    break;
                ret = ret * 10 + str[cur_pos] - '0';
                cur_pos++;
            }
            ret *= flag;
            if(ret > INT_MAX)
                ret = INT_MAX;
            if(ret < INT_MIN)
                ret = INT_MIN;
            return ret;
        }
};
