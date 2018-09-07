//only digits 1-9 and the character '.'.
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
      dfs(board, 0, 0);
    }

    bool dfs(vector<vector<char>> &board, int i, int j) {
      if (i == 9) return true;
      if (j == 9) return dfs(board, i + 1, 0);
      if (board[i][j] != '.') return dfs(board, i, j + 1);
      for (char c = '1'; c <= '9'; ++c) {
        if (valid(board, i, j, c)) {
          board[i][j] = c;
          if (dfs(board, i, j + 1)) return true;
          board[i][j] = '.';
        }
      }
      return false;
    }

    bool valid(vector<vector<char>> &board, int i, int j, char c) {
      int x = (i / 3) * 3;
      int y = (j / 3) * 3;
      for (int k = 0; k < 9; ++k) {
        if (board[i][k] == c) return false;
        if (board[k][j] == c) return false;
        if (board[x + k % 3][y + k / 3] == c) return false;
      }
      return true;
    }
};