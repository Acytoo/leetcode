import java.util.*;

public class J1529bulbSwitcherIV {
  public static void main(String[] args) {
    Solution s = new Solution();

  }
}

class Solution {
  public int minFlips(String target) {
    int res = 0;
    char pre = '0';
    for (int i = 0, stop = target.length(); i < stop; ++i)
      if (target.charAt(i) != pre) {
        ++res;
        pre = target.charAt(i);
      }
    return res;
  }
}
