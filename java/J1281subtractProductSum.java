import java.util.*;

public class J1281subtractProductSum {
  public static void main(String[] args) {
    Solution s = new Solution();

  }
}

class Solution {
  public int subtractProductAndSum(int n) {
    int product = 1, sum = 0;
    int cur = 0;
    while (n != 0) {
      cur = n % 10;
      product *= cur;
      sum += cur;
      n /= 10;
    }
    return product - sum;
  }

}
