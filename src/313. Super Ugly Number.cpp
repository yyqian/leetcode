class Solution {
 public:
  int nthSuperUglyNumber(int n, vector<int>& primes) {
    vector<int> idx(primes.size(), 0);
    vector<int> ugly(1, 1);
    for (int i = 1; i < n; ++i) {
      int next = INT_MAX;
      for (int p = 0; p < primes.size(); ++p) {
        next = min(next, primes[p] * ugly[idx[p]]);
      }
      ugly.push_back(next);
      for (int p = 0; p < primes.size(); ++p) {
        if (next == primes[p] * ugly[idx[p]]) {
          idx[p]++;
        }
      }
    }
    return ugly[n - 1];
  }
};