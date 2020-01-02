import java.util.*;

public class J371sum {
  public static void main(String[] args) {
    Solution s = new Solution();

  }
}
/*

a = 5, b = 17, sum = 22
a_bin = 101, b_bin = 10001

sum = a ^ b
carry = (a & b) << 1

return getSum(sum, carry)

 */
class Solution {
    public int getSum(int a, int b) {
        while(b != 0) {
            int c = a&b;
            a = a^b;
            b = c<<1;
        }
        return a;
    }

    public int getSum1(int a, int b) {
        return Integer.sum(a, b);
    }
}
