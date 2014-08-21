class Solution {
public:
    int atoi(const char *str) {
        if(!str)
            return 0;
        int s = 1;
        long long res = 0;
        const char *p = str;
        while(p && *p == ' ')
            p++;
        if(!p)
            return 0;
        if(*p == '-') {
            p++;
            s = -1;
        } else if(*p == '+') {
            p++;
            s = 1;
        }
        while(*p) {
            if(!('0' <= *p && *p <= '9'))
                break;
            if(res > INT_MAX / 10 || (res == INT_MAX / 10 &&
                                *p - '0' > INT_MAX % 10))
                return s == 1 ? INT_MAX : INT_MIN;
            res = res * 10 + *p - '0';
            p++;
        }
        return res * s;
    }
};
