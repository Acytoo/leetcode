import java.util.*;

public class J1219maximumGold {
  public static void main(String[] args) {
    Solution s = new Solution();

  }
}
// faster solution from leetcode
class Solution {
    public int getMaximumGold(int[][] grid) {
	    // initialize 2D array with boundary filled with zero cells for simpler code
        int [][] matrix = new int[grid.length + 2][grid[0].length + 2];
        for(int i = 0; i< grid.length; i++) {
            for(int j = 0; j< grid[0].length; j++) {
                matrix[i + 1][j + 1] = grid[i][j];
            }
        }
        int max = 0;
		// run dfs in the cases described above
        for(int i = 1; i<= grid.length; i++) {
            for(int j = 1; j<= grid[0].length; j++) {
                int zeroCount = 0;
                if (matrix[i - 1][j] == 0) zeroCount++; // top
                if (matrix[i][j - 1] == 0) zeroCount++; // left
                if (zeroCount == 2) { // For top left corner
                    max = Math.max(max, dfs(matrix, i, j));
                } else {
                    if (matrix[i + 1][j] == 0) zeroCount++;
                    if (matrix[i][j + 1] == 0) zeroCount++;
                    if (zeroCount >= 3) {  // Surrounded by 3 or 4 zero cells
                        max = Math.max(max, dfs(matrix, i, j));
                    }
                }
            }
        }
        return max;
    }
    // typical DFS.
    int directions[][] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int dfs(int[][] matrix, int y, int x) {
        if (y < 0 || y >= matrix.length || x < 0 || x >= matrix[0].length || matrix[y][x] == 0) return 0;
        int max = 0;
        int current = matrix[y][x];
        matrix[y][x] = 0;
        for(int i = 0; i < 4; i++) {
            max = Math.max(max, dfs(matrix, y + directions[i][0], x + directions[i][1]));
        }
        matrix[y][x] = current;
        return max + current;
    }
}

// dp or greedy?
class Solution {
  public int getMaximumGold(int[][] grid) {
    m_ = grid.length;
    n_ = grid[0].length;
    grid_ = grid;

    int res = 0;
    for (int i=0; i<m_; ++i)
      for (int j=0; j<n_; ++j)
        res = Math.max(res, dfs(i, j));
    return res;
  }
  private int dfs(final int a, final int b) {
    if (a<0 || m_<=a || b<0 || n_<=b || grid_[a][b]==0)
      return 0;
    int c = grid_[a][b];
    grid_[a][b] = 0;
    int newGold = c + Collections.max(Arrays.asList(dfs(a-1, b), dfs(a+1, b), dfs(a, b-1), dfs(a, b+1)));
    // int tmp = c;
    grid_[a][b] = c;
    return newGold;
  }
  private int m_;
  private int n_;
  private int[][] grid_;
}
