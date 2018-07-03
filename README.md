# leetcode
leetcode in c++

important: 15, 74, 105, 200, 236, 39 & 40 & 46, 43

redo: 31, 33

binary_search 变种：rotated， duplicated

cpp:

```
// vector
v.size()
v.push_back(val)
v.pop_back()
val = v.front()
val = v.back()
// set
s.insert(val)
s.erase(val)
s.find(val) != s.end() // s contains val
// algorithm
sort(v.begin(), v.end());
auto result = find(v.begin, v.end(), target); // contains: result != v.end()
```

贪婪, DP, 回溯, 分治

General Backtrack:

```
void backtrack(vector<vector<int>> &result, vector<int> &path, vector<int> nums, ...) {
  if (条件满足) {
    result.push_back(path);
    return;
  }
  for (int i = 0; i < nums.size(); ++i) {
    if (i 不满足条件) {
      continue;
    }
    path.push_back(nums[i]);
    backtrack(res, path, nums, ...); // 求解空间减小
    path.pop_back();
  }
}
```