import java.util.*;

public class J1309decryptString {
  public static void main(String[] args) {
    Solution s = new Solution();

  }
}

class Solution {
  public String freqAlphabets(String s) {

    char[] charS = s.toCharArray();
    int n = charS.length;
    StringBuilder res = new StringBuilder();
    for (int i=n-1; i>=0; --i) {
      if (charS[i] ==  '#') {
        res.append(getChar(charS[i-2], charS[i-1]));
        i = i - 2;
      } else {
        res.append(getChar(charS[i]));
      }
    }
    return res.reverse().toString();

  }
  private static final char getChar(char a) {
    return (char) (a-'1'+'a');
  }
  private static final char getChar(char a, char b) {
    return (char) (10*(a-'1')+(b-'0')+'j');
  }

}
