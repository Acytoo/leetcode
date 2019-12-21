public class J200numberOfIslands {
  public static void main(String[] args) {
    char[][] a =
        {{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'}};
    Solution s = new Solution();
    int res = s.numIslands(a);
    System.out.println(res);
  }
}

class Solution {
  public int numIslands(char[][] grid) {
    // Brute force
    int res = 0;
    for (int i=0; i<grid.length; ++i) {
      for (int j=0; j<grid[i].length;  ++j) {
        // find the island and convert the island to '0'
        if (grid[i][j] == '1') {
          // convert the conneted grid to '0' and res++
          ++res;
          bfs(grid, i, j);
        }
      }
    }
    return res;
  }

  private void bfs(char[][] grid, int i, int j) {
    if (i<0 || i>=grid.length || j<0 || j>=grid[i].length || grid[i][j] == '0')
      return;
    grid[i][j] = '0';
    bfs(grid, i+1, j);
    bfs(grid, i-1, j);
    bfs(grid, i, j+1);
    bfs(grid, i, j-1);
  }
}
