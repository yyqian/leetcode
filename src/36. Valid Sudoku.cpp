class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
      for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
          if (!valid(board, i, j)) return false;
        }
      }
      return true;
    }

    bool valid(vector<vector<char>> &board, int i, int j) {
      char c = board[i][j];
      if (c == '.') return true;
      int x = i - (i % 3);
      int y = j - (j % 3);
      for (int k = 0; k < 9; ++k) {
        if (k != j && board[i][k] == c) return false;
        if (k != i && board[k][j] == c) return false;
        int m = x + k / 3;
        int n = y + k % 3;
        if (m != i && n != j && board[m][n] == c) return false;
      }
      return true;
    }
};

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
      vector<vector<bool>> rowUsed(board.size(), vector<bool>(9, false));
      vector<vector<bool>> colUsed(board[0].size(), vector<bool>(9, false));
      vector<vector<bool>> squareUsed(9, vector<bool>(9, false));
      for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
          if (board[i][j] == '.') continue;
          int n = board[i][j] - '1';
          int k = (i / 3) * 3 + j / 3;
          if (rowUsed[i][n] || colUsed[j][n] || squareUsed[k][n]) return false;
          rowUsed[i][n] = true;
          colUsed[j][n] = true;
          squareUsed[k][n] = true;
        }
      }
      return true;
    }
};