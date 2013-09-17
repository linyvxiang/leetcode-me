class Solution {
public:
    int atoi(const char *str) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
      long long ans = 0;
      int flag = 1;
      int len = strlen(str);
      if(!str || strlen(str) == 0)
        return 0;
      int i = 0;
      while(*str == ' ')
        str++;
      if(*str == '-') {
          flag = -1;
          str++;
      } else if(*str == '+') {
          flag = 1;
          str++;
      }
      for(; *str != '\0'; str++) {
          if(*str >= '0' && *str <= '9') {
              ans = ans *10 + (*str) - '0';
          } else {
              break;
          }
      }
      ans *= flag;
      if(ans > INT_MAX)
        ans = INT_MAX;
      else if(ans < INT_MIN)
        ans = INT_MIN;
      return (int)ans;
    }
};
