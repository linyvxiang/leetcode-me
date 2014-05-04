class Solution {
public:
  int fac(int n)
  {
      if(n == 0 || n == 1)
        return 1;
      int i, res = 1;
      for(i = 2; i <= n; i++)
        res *= i;
      return res;
  }
  string do_slove(string str, int n, int k)
  {
      string res;
      string temp(str);
      int base = fac(n - 1);
      --k;
      int i;
      for(i = n - 1; i > 0; i--) {
          auto pos = next(temp.begin(), k / base);
          res.push_back(*pos);
          temp.erase(pos);
          k = k % base;
          base = base / i;
      }
      res.push_back(temp[0]);
      return res;
  }
  string getPermutation(int n, int k) {
        string res(n, '0');
        int i;
        for(i = 0 ;i < n; i++) {
            res[i] += (i + 1);
        }
       string fin =  do_slove(res, n, k);
       return fin;
  }
};
