class Solution {
public:
    int atoi(const char *str) {
        if(!str)
            return 0;
        long long res = 0;
        int s = 1;
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
            if(!(*p >= '0' && *p <= '9'))
                break;
            res = res * 10 + *p - '0';
            p++;
        }
        res *= s;
        if(res > INT_MAX)
            res = INT_MAX;
        if(res < INT_MIN)
            res = INT_MIN;
        return (int)res;
    }
};
