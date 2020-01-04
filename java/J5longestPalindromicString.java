import java.util.*;

public class J5longestPalindromicString {
  public static void main(String[] args) {
    Solution s = new Solution();
    String a = "hellooo";
    String res = s.longestPalindrome(a);
    System.out.println(res);
  }
}


class Solution {
  public String longestPalindrome(String s) {
    s_ = s;
    lenS_ = s.length();
    int len = 0, start = 0;
    for (int i=0; i<lenS_; ++i) {
      int cur = Math.max(palinLen(i, i), palinLen(i, i+1));
      if (cur > len) {
        len = cur;
        start = i - (cur-1) / 2;
      }
    }
    return s.substring(start, start+len);
  }

  private int palinLen(int l, int r) {
    while (l>=0 && r<lenS_ && s_.charAt(l) == s_.charAt(r)) {
      --l;
      ++r;
    }
    return r-l-1;
  }
  private String s_;
  private int lenS_;
}
