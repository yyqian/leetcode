class Solution {
public:
    int integerReplacement(int n) {
      unordered_map<int, int> cache;
      return integerReplacement(n, cache);
    }
private:
    int integerReplacement(int n, unordered_map<int, int> &cache) {
        if (n == 1) return 0;
        if (cache.count(n) == 0) {
          if ((n & 1) == 0) {
            cache[n] = 1 + integerReplacement(n / 2, cache);
          } else {
            cache[n] = 2 + min(integerReplacement(n/2, cache), integerReplacement(n/2 + 1, cache));
          }
        }
        return cache[n];
    }
};
