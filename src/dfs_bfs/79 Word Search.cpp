/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
*/
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
      for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[0].size(); ++j) {
          if (find(board, word, 0, i, j)) {
            return true;
          }
        }
      }
      return false;
    }

    bool find(vector<vector<char>>& board, string &word, int idx, int i, int j) {
      if (idx == word.size()) {
        return true;
      }
      if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[idx]) {
        return false;
      }
      board[i][j] = '/0';
      bool found = find(board, word, idx + 1, i + 1, j)
            || find(board, word, idx + 1, i - 1, j)
            || find(board, word, idx + 1, i, j + 1)
            || find(board, word, idx + 1, i, j -1);
      board[i][j] = word[idx];
      return found;
    }
};