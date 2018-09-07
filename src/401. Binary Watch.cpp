// 4, 6
class Solution {
public:
    vector<string> readBinaryWatch(int num) {
      vector<int> pool1 {1, 2, 4, 8};
      vector<int> pool2 {1, 2, 4, 8, 16, 32};
      vector<string> res;
      for (int i = 0; i <= num; ++i) {
        vector<int> left;
        vector<int> right;
        helper(left, pool1, i);
        helper(right, pool2, num - i);
        for (int l : left) {
          for (int r : right) {
            if (l >= 12) continue;
            if (r >= 60) continue;
            string ls = to_string(l);
            string rs;
            if (r < 10) {
              rs = "0" + to_string(r);
            } else {
              rs = to_string(r);
            }
            res.push_back(ls + ":" + rs);
          }
        }
      }
      return res;
    }

    void helper(vector<int> &comb, vector<int> &pool, int n) {
      dfs(comb, pool, n, 0, 0);
    }

    void dfs(vector<int> &comb, vector<int> &pool, int count, int start, int pathSum) {
      if (count == 0) {
        comb.push_back(pathSum);
        return;
      }
      for (int i = start; i < pool.size(); ++i) {
        dfs(comb, pool, count - 1, i + 1, pathSum + pool[i]);
      }
    }
};