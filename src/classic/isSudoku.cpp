bool isValidSudoku(vector<vector<char>>& board) {
  vector<vector<bool> usedX(board.size(), vector<bool>(9, false));
  vector<vector<bool> usedY(board[0].size(), vector<bool>(9, false));
  vector<vector<bool> usedQ(9, vector<bool>(9, false));
  for (int i = 0; i < board.size(); ++i) {
    for (int j = 0; j < board[0].size(); ++j) {
      int k = (i / 3) * 3 + j / 3;
      char c = board[i][j];
      if (c == '.') continue;
      int x = c - '1';
      if (usedX[i][x] || usedY[j][x] || usedQ[k][x]) return false;
      usedX[i][x] = true;
      usedY[j][x] = true;
      usedQ[k][x] = true;
    }
  }
  return true;
}