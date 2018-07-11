/*
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"

Corner Cases:

Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".
*/
class Solution {
public:
    string simplifyPath(string path) {
      stack<string> stk;
      int i = 0;
      int j = 1;
      while (j < path.size()) {
        while (j < path.size() && path[j] != '/') {
          ++j;
        }
        if (i + 1 != j) {
          string dir = path.substr(i + 1, j - i - 1);
          if (dir == ".") {
          } else if (dir == "..") {
            if (!stk.empty()) stk.pop();
          } else {
            stk.push(dir);
          }
        }
        i = j;
        j++;
      }
      string res;
      while (!stk.empty()) {
        res = '/' + stk.top() + res;
        stk.pop();
      }
      return res.empty() ? "/" : res;
    }
};