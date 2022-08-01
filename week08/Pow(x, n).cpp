/// TC: O(logN) N is the power of the operation
/// MC: O(logH) H is height of recursion

class Solution {
public:
    double po(double x, long long n)
    {
      double res;
      if(n == 0) return 1.0;
      if(n == 1) return x;
      if(n % 2 == 0) return res *= res = po(x, n / 2);
      return po(x, n - 1) * x;
    }
    double myPow(double x, int n) {
      long long t = n;
      t = t < 0 ? (-1*t) : t;
      double ans = po(x, t);
      return n < 0 ? (1.0 / ans) : ans;
    }
};
