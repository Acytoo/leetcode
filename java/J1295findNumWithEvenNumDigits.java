import java.util.*;

public class J1295findNumWithEvenNumDigits {
  public static void main(String[] args) {
    Solution s = new Solution();

  }
}

class Solution {
  public int findNumbers(int[] nums) {
    int res = 0;
    for (int i: nums)
      if (isEven(i))
        ++res;
    return res;

  }
  private final boolean isEven(int num) {
    if (num < 10)
      return false;
    if (num < 100)
      return true;
    if (num < 1000)
      return false;
    if (num < 10000)
      return true;
    return false;
  }
}
