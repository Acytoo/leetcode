import java.util.*;


public class J69sqrt {
  public static void main(String[] args) {
    Solution s = new Solution();
    System.out.println(s.mySqrt(9));
  }
}

class Solution {
  public int mySqrt(int x) {
    int l = 1, r = x;
    while (l <= r) {
      int m = (l+r) >> 1;
      if (m > x/m)
        r = m - 1;
      else
        l = m + 1;
    }
    return r;
  }
}
