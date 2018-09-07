/*
Suppose you have a random list of people standing in a queue. Each person is
described by a pair of integers (h, k), where h is the height of the person
and k is the number of people in front of this person who have a height greater
than or equal to h. Write an algorithm to reconstruct the queue.

Note:
The number of people is less than 1,100.

Example

Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
*/
class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
      vector<bool> used(people.size(), false);
      vector<pair<int, int>> res;
      dfs(people, used, res);
      return res;
    }

    bool dfs(vector<pair<int, int>> &people, vector<bool> &used, vector<pair<int, int>> &res) {
      if (res.size() == people.size()) return true;
      for (int i = 0; i < people.size(); ++i) {
        if (!used[i] && valid(res, people[i])) {
          used[i] = true;
          res.push_back(people[i]);
          if (dfs(people, used, res)) return true;
          res.pop_back();
          used[i] = false;
        }
      }
      return false;
    }

    bool valid(vector<pair<int, int>> &res, pair<int, int> &p) {
      int cnt = 0;
      for (auto ele : res) {
        if (ele.first >= p.first) ++cnt;
      }
      return cnt == p.second;
    }

};

/*
Below is my explanation of the following neat solution where we sort people from tall to short (and by increasing k-value) and then just insert them into the queue using their k-value as the queue index:

def reconstructQueue(self, people):
    people.sort(key=lambda (h, k): (-h, k))
    queue = []
    for p in people:
        queue.insert(p[1], p)
    return queue
I didn't come up with that myself, but here's my own explanation of it, as I haven't seen anybody explain it (and was asked to explain it):

People are only counting (in their k-value) taller or equal-height others standing in front of them. So a smallest person is completely irrelevant for all taller ones. And of all smallest people, the one standing most in the back is even completely irrelevant for everybody else. Nobody is counting that person. So we can first arrange everybody else, ignoring that one person. And then just insert that person appropriately. Now note that while this person is irrelevant for everybody else, everybody else is relevant for this person - this person counts exactly everybody in front of them. So their count-value tells you exactly the index they must be standing.

So you can first solve the sub-problem with all but that one person and then just insert that person appropriately. And you can solve that sub-problem the same way, first solving the sub-sub-problem with all but the last-smallest person of the subproblem. And so on. The base case is when you have the sub-...-sub-problem of zero people. You're then inserting the people in the reverse order, i.e., that overall last-smallest person in the very end and thus the first-tallest person in the very beginning. That's what the above solution does, Sorting the people from the first-tallest to the last-smallest, and inserting them one by one as appropriate.

Now that's my explanation. If you have a different one, I'm interested to see it :-)
*/