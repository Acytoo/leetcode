import java.util.*;

public class J1047removeAdjacent {
  public static void main(String[] args) {
    Solution s = new Solution();
    String a = "asdffs";
    System.out.println(s.removeDuplicates(a));
  }
}


class Solution {
  public String removeDuplicates(String s) {
    int i = 0, n = s.length();
    char[] res = s.toCharArray();
    for (int j=0; j<n; ++j, ++i) {
      res[i] = res[j];
      if (i > 0 && res[i - 1] == res[i])
        i -= 2;
    }
    return new String(res, 0, i);
  }
}
