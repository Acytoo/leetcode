import java.util.*;

public class J831maskingInfo {
  public static void main(String[] args) {
    Solution s = new Solution();

  }
}

class Solution {
  public String maskPII(String S) {
    String res;
    if (S.charAt(S.length()-1) <= '9') {  // phone
      res =  maskPhone(S);
    } else {  // mail
      res = maskMail(S);
    }
    return res;
  }

  private String maskPhone(String S) {
    char[] s = S.toCharArray();
    int n = s.length;
    StringBuilder res = new StringBuilder();
    int tail = 4;
    while (tail > 0) {
      if (s[--n] < '0')
        continue;
      res.append(s[n]);
      --tail;
    }
    res.append("-***-***");
    int maskInt = 6;
    while (maskInt > 0) {
      if (s[--n] < '0')
        continue;
      --maskInt;
    }

    int countInt = 0;
    while (n > 0) {
      if (s[--n] < '0')
        continue;
      ++countInt;
    }

    if (countInt == 0)
      return res.reverse().toString();

    res.append('-');
    while (countInt-- > 0) {
      res.append('*');
    }
    res.append('+');
    return res.reverse().toString();
  }

  private String maskMail(String S) {
    char[] s = S.toCharArray();
    int n = s.length;
    int diff = 'a' - 'A';
    StringBuilder res = new StringBuilder();
    while (s[--n] != '@') {
      if (s[n] >= 'a')
        res.append(s[n]);
      else if (s[n] >= 'A')
        res.append((char) (s[n] + diff));
      else
        res.append('.');
    }
    res.append('@');
    if (s[--n] >= 'a')
      res.append(s[n]);
    else
      res.append((char)(s[n] + diff));

    res.append("*****");

    if (s[0] >= 'a')
        res.append(s[0]);
    else
      res.append((char)(s[0] + diff));

    return res.reverse().toString();
  }
}
