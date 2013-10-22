class Solution {
public:
    double pow(double x, int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
      bool negative = false;
      if(n < 0)
        negative = true;
      double result = 1.0;
      while(n) {
          if(n & 1) 
            result *= x;
          x *= x;
          n /= 2;
      }
      if(negative)
        return 1 / result;
      return result;
    }
};
