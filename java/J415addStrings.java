import java.util.*;

public class J415addStrings {
  public static void main(String[] args) {
    Solution s = new Solution();
    String a = "123", b = "12349";
    String res = s.addStrings(a, b);
    System.out.println(res);
  }
}

class Solution {
    public String addStrings(String n1, String n2) {
        int i = n1.length() - 1 , j = n2.length() - 1;
        if (i < j)
            return addStrings(n2, n1); // make sure n1.len >= n2.len

        int carry = 0;
        StringBuilder res = new StringBuilder();
        final int kBase = '0'+'0';
        int idx = 0;
        while (0 <= i && 0 <= j) {
            int tmp = n1.charAt(i) + n2.charAt(j) + carry - kBase;
            if (tmp > 9) {
                tmp -= 10;
                carry = 1;
            } else {
                carry = 0;
            }
            res.append((char) (tmp+'0'));
            ++idx;
            --i;
            --j;
        }

        while (0 <= i) {
            int tmp = n1.charAt(i) + carry - '0';
            if (tmp > 9) {
                tmp -= 10;
                carry = 1;
            } else {
                carry = 0;
            }
            res.append((char) (tmp+'0'));
            ++idx;
            --i;
        }
        if (carry == 1)
            res.append(1);
        return res.reverse().toString();
    }
}
