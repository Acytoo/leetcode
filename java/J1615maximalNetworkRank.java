import java.util.*;

public class J1615maximalNetworkRank {
  public static void main(String[] args) {
    Solution s = new Solution();

  }
}

class Solution {
  public int maximalNetworkRank(int n, int[][] roads) {
    int[][] g = new int[n][n];
    int[] cites = new int[n];
    int cur = 0, res = 0;
    for (int[] road: roads) {
      ++cites[road[0]]; ++cites[road[1]];
      g[road[0]][road[1]] = 1; g[road[1]][road[0]] = 1;
    }
    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j) {
        cur = cites[i] + cites[j] - g[i][j];
        res = Math.max(res, cur);
      }
    return res;
  }
}
