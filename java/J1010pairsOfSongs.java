import java.util.*;

public class J1010pairsOfSongs {
  public static void main(String[] args) {
    Solution s = new Solution();

  }
}

// similar to two sum
class Solution {
  public int numPairsDivisibleBy60(int[] time) {
    int c[]  = new int[60], res = 0;
    for (int t : time) {
      res += c[(600 - t) % 60];
      c[t % 60] += 1;
    }
    return res;
  }
}
