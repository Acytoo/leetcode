import java.util.*;

public class J392isSubsequence {
  public static void main(String[] args) {
    Solution s = new Solution();
    // String a = "abc", b = "qwearrfsdcsvasdbsdc";
    String a = "leeeeetcode", b = a + "adsad";
    System.out.println(s.isSubsequence(a, b));
  }
}

class Solution {
    public boolean isSubsequence(String s, String t) {
        int i = 0, j = 0, n = t.length(), m = s.length();
        if (m == 0)
            return true;
        while (j < n && i < m) {
            if (s.charAt(i) == t.charAt(j))
                ++i;
            ++j;
        }
        return m == i;
    }
}
