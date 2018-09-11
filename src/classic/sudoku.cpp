void solveSudoku(vector<vector<char>>& board) {
  solve(board, 0, 0);
}

bool solve(vector<vector<char>> &board, int i, int j) {
  if (i == 9) return true;
  if (j == 9) return solve(board, i + 1, 0);
  if (board[i][j] != '.') return solve(board, i, j + 1);
  for (char c = '1'; c <= '9'; ++k) {
    if (valid(board, i, j, c)) {
      board[i][j] = c;
      if (solve(board, i, j + 1)) return true;
      board[i][j] = '.';
    }
  }
  return false;
}

bool valid(vector<vector<char>> &board, int i, int j, char c) {
  int m = i - i % 3;
  int n = j - j % 3;
  for (int x = 0; x < 9; ++x) {
    if (board[i][x] == c) return false;
    if (board[x][j] == c) return false;
    if (board[m + x / 3][n + x % 3] == c) return false;
  }
  return true;
}
