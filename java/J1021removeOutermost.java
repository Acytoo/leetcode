import java.util.*;

public class J1021removeOutermost {
  public static void main(String[] args) {
    Solution s = new Solution();

  }
}

class Solution {
  public String removeOuterParentheses(String S) {
    StringBuilder res = new StringBuilder();
    int par = 0, start = 1;
    char[] s = S.toCharArray();
    for (int i=0, stop=s.length; i<stop; ++i) {
      if (s[i] == '(') {
        ++par;
      } else {
        --par;
      }
      if (par == 0) {
        res.append(s, start, i-start);
        start = i+2;
      }
    }
    return res.toString();
  }
}
