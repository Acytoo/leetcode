import java.util.*;

public class J504base7 {
  public static void main(String[] args) {
    Solution s = new Solution();
    System.out.println(s.convertToBase7(-100));
  }
}

class Solution {
    public String convertToBase7(int num) {
        if (num == 0)
            return "0";
        boolean neg = false;
        if (num < 0) {
            num = -num;
            neg = true;
        }
        StringBuilder res = new StringBuilder();
        int rem = 0;
        while (num != 0) {
            rem = num % 7;
            num = num / 7;
            res.append((char) ('0'+rem));
        }
        if (neg)
            res.append('-');
        return res.reverse().toString();
    }
}
