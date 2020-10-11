import java.util.*;

public class J1614maximumNestingDepthOfTheParentheses {
  public static void main(String[] args) {
    Solution s = new Solution();

  }
}

class Solution {
  public int maxDepth(String s) {
    int cur = 0, res = 0;
    for (int i = 0, n = s.length(); i < n; ++i)
      if (s.charAt(i) == '(')
        res = Math.max(res, ++cur);
      else if (s.charAt(i) == ')')
        --cur;
    return res;
  }
}
