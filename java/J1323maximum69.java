import java.util.*;

public class J1323maximum69 {
  public static void main(String[] args) {
    Solution s = new Solution();

  }
}

// 1 <= num <= 10^4
// 6 <= num <= 9999
class Solution {
  public int maximum69Number (int num) {
    if (num <=9)
      return 9;
    if (num <= 99) {
       if ((num / 10) == 6)
        return (num % 10) + 90;
      return 99;
    }
    if (num <= 999) {
      if ((num / 100) == 6)
        return (num % 100) + 900;
      if (((num-900) / 10) == 6)
        return (num%10) + 990;
      return 999;
    }
    if ((num / 1000) == 6)
      return (num % 1000) + 9000;
    if (((num-9000) / 100) == 6)
      return (num % 100) + 9900;
    if (((num-9900) / 10) == 6)
      return (num % 10) + 9990;
    return 9999;
  }
}
