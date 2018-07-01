#include <climits>

class Solution {
 public:
  int divide(int dividend, int divisor) {
    long dividendL = dividend;
    long divisorL = divisor;
    bool pos = dividend >= 0 && divisor > 0 || dividend <= 0 && divisor < 0;
    dividendL = dividendL > 0 ? dividendL : -dividendL;
    divisorL = divisorL > 0 ? divisorL : -divisorL;
    long res = helper(dividendL, divisorL);
    if (pos && res > INT_MAX) {
      return INT_MAX;
    } else if (!pos && -res < INT_MIN) {
      return INT_MIN;
    }
    return pos ? res : -res;
  }

 private:
  long helper(long dividend, long divisor) {
    if (dividend < divisor) {
      return 0;
    }
    long multiply = 1;
    long tmp = divisor;
    while (true) {
      long diff = dividend - tmp;
      if (diff == 0) {
        return multiply;
      }
      tmp = tmp << 1;
      if (dividend < tmp) {
        return multiply + helper(diff, divisor);
      }
      multiply = multiply << 1;
    }
  }
};