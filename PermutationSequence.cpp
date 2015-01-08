class Solution {
public:
    string getPermutation(int n, int k) {
       vector<char> nums; 
       for(int i = 1; i <= n; i++)
           nums.push_back(i + '0');
       string ret;
       k--;
       while(nums.size() > 1) {
           int cur_pos = k / fac(nums.size() - 1);
           k %= fac(nums.size() - 1);
           ret += nums[cur_pos];
           nums.erase(nums.begin() + cur_pos);
       }
       ret += nums[0];
       return ret;
    }
private:
    int fac(int n)
    {
        if(n == 0 || n == 1)
            return n;
        return n * fac(n - 1);
    }
};
