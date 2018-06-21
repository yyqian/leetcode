#include <string>
using namespace std;
class Solution {
 public:
  string intToRoman(int num) {
    string res;
    string c[] = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                  "XL", "X",  "IX", "V",  "IV", "I"};
    int n[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    int len = sizeof(n) / sizeof(n[0]);
    int count = 0;
    for (int i = 0; i < len; ++i) {
      if (num == 0) {
        break;
      }
      count = num / n[i];
      num -= count * n[i];
      while (count-- != 0) {
        res += c[i];
      }
    }
    return res;
  }
};