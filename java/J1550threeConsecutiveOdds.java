import java.util.*;

public class J1550threeConsecutiveOdds {
  public static void main(String[] args) {
    Solution s = new Solution();

  }
}

class Solution {
  public boolean threeConsecutiveOdds(int[] arr) {
    int odd = 0;
    for (int a: arr) {
      if ((a & 1) == 1) {  // odd
        ++odd;
        if (odd == 3) return true;
      } else {
        odd = 0;
      }
    }
    return false;
  }
}
