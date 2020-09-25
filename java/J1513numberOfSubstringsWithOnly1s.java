import java.util.*;

public class J1513numberOfSubstringsWithOnly1s {
  public static void main(String[] args) {
    Solution s = new Solution();

  }
}

class Solution {
  public int numSub(String s) {
    final int kMod = 1_000_000_007;
    int res = 0, cur = 0;
    for (int i = 0, stop = s.length(); i < stop; ++i) {
      cur = s.charAt(i) == '0'? 0: cur + 1;
      res = (res + cur) % kMod;
    }
    return res;
  }
}
