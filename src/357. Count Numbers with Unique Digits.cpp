class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        if (n == 1) return 10;
        vector<int> dp(n + 1);
        dp[1] = 10;
        dp[2] = 81;
        for (int i = 2; i < n; ++i) {
          dp[i + 1] = dp[i] * (10 - i);
        }
        int res = 0;
        for (int i = 1; i <= n; ++i) {
          res += dp[i];
        }
        return res;
    }
};