import java.util.*;

public class J507perfectNumber {
  public static void main(String[] args) {
    Solution s = new Solution();
    System.out.println(s.checkPerfectNumber(10));
  }
}

class Solution {
    public boolean checkPerfectNumber(int num) {
        if (num <= 3)
            return false;
        int stop = (int) Math.sqrt(num);
        int sum = 1;
        for (int i=2; i<=stop; ++i)
            if (num % i == 0)
                sum += i + num / i;
        return sum==num;
    }
}
