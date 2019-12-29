import java.util.*;

public class J746minCostClimbing {
  public static void main(String[] args) {
    Solution s = new Solution();

  }
}

class Solution {
  public int minCostClimbingStairs(int[] cost) {
    int n = cost.length;
    if (n == 2)
      return Math.min(cost[0], cost[1]);
    ++n;
    int[] tmp = new int[n];
    tmp[0] = 0;
    tmp[1] = 0;
    // tmp[i] = min(tmp[i-1]+cost[i-1], tmp[i-2]+cost[i-2])
    for (int i=2; i<n; ++i) {
      tmp[i] = Math.min(tmp[i-1]+cost[i-1], tmp[i-2]+cost[i-2]);
    }
    return tmp[n-1];
  }

}
