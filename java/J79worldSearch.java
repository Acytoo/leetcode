import java.util.*;

public class J1234Template {
  public static void main(String[] args) {
    Solution s = new Solution();

  }
}

class Solution {
  public boolean exist(char[][] board, String word) {
    boolean[][] used = new boolean[board.length][board[0].length];
    char[] w = word.toCharArray();
    int m = board.length, n = board[0].length;

    for (int i=0; i<board.length; ++i)
      for (int j=0; j<board[0].length; ++j)
        if (board[i][j] == w[0]) {
          used[i][j] = true;
          if (found(board, i, j, w, 0, used, m, n))
            return true;
          else
            used[i][j] = false;
        }
    return false;
  }

  public boolean found(char[][]board, int x, int y,
                       char[] word, int idx, boolean[][] used,
                       int m, int n) {

    if (idx == word.length-1) {
      return true;
    }

    if (x+1 < m && !used[x+1][y] && board[x+1][y] == word[idx+1]) {
      used[x+1][y] = true;
      if (found(board, x+1, y, word, idx+1, used, m, n))
        return true;
      else
        used[x+1][y] = false;
    }
    if (x-1 >= 0 && !used[x-1][y] && board[x-1][y] == word[idx+1]) {
      used[x-1][y] = true;
      if (found(board, x-1, y, word, idx+1, used, m, n))
        return true;
      else
        used[x-1][y] = false;
    }
    if (y+1 < n && !used[x][y+1] && board[x][y+1] == word[idx+1]) {
      used[x][y+1] = true;
      if (found(board, x, y+1, word, idx+1, used, m, n))
        return true;
      else
        used[x][y+1] = false;
    }
    if (y-1 >= 0 && !used[x][y-1] && board[x][y-1] == word[idx+1]) {
      used[x][y-1] = true;
      if (found(board, x, y-1, word, idx+1, used, m, n))
        return true;
      else
        used[x][y-1] = false;
    }

    return false;
  }
}
