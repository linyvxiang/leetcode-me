class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
       vector<vector<int>> res;
       if(num.empty() || num.size() < 3)
            return res;
       vector<int> tmp_res;
       sort(num.begin(), num.end());
       int i, k, l;
       int a, b, c, n = num.size();
       for(i = 0; i < n - 2; i++) {
           a = num[i];
           k = i + 1;
           l = n - 1;
           while(k < l) {
               b = num[k];
               c = num[l];
               if(a + b + c == 0) {
                   tmp_res.push_back(a);
                   tmp_res.push_back(b);
                   tmp_res.push_back(c);
                   res.push_back(tmp_res);
                   tmp_res.clear();
                   k++;
                   l--;
                   while(k < l && num[k] == num[k - 1])
                        k++;
                   while(k < l && num[l] == num[l + 1])
                        l--;
               }  else if(a + b + c > 0) {
                   l--;
               } else {
                   k++;
               }
           }
           if(i < n - 1) {
               while(num[i] == num[i + 1])
                i++;
           }
       }
       return (res);
    }
};
