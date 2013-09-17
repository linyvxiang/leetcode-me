class Solution {
public:
    int reverse(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!x)
            return 0;
        int ans = 0;
        while(x) {
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        return ans;
    }
};
