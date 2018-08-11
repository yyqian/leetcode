# leetcode
leetcode in c++

important: 15, 74, 105, 200, 236, 39 & 40 & 46, 43, 55, 81, 90, 96

redo: 31, 33

binary_search 变种：rotated， duplicated

cpp:

```
// string
string strNew = str + 'c'
string strNew = str + "car"
string strNew = str + (char)56
bool eq = str1 == str2
bool eq = str == "car"

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

// queue
q.front()
q.back()
q.pop()
q.push()

// stack
stk.top()
stk.pop()
stk.push()

// unordered_set
st.erase(iter)
st.erase(val)
st.insert(val)
st.find(val) != st.end()

// unordered_map
unordered_map<int, string> st {{1, "one"}, {2, "two"}};
auto it = st.find(1);
if (it != st.end()) std::cout << it->first << ":" << it->second;

// algorithm
sort(v.begin(), v.end());
reverse(v.begin(), v.end());
swap(v[i], v[j]);
auto result = find(v.begin(), v.end(), target); // contains: result != v.end()
int idx = result - v.begin();
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

DP 从 recur 转 iter 可以用 mem 数组

Well Known:

- 拓扑排序
- 优先队列
- LRU
- Trie 树
- 堆
- 快排
