import java.util.*;

public class J678validParenthesis {
  public static void main(String[] args) {
    Solution s = new Solution();

  }
}


class Solution {
  public boolean checkValidString(String s) {
    int low = 0, up = 0;
    for (int i=0, stop=s.length(); i<stop; ++i) {
      char c = s.charAt(i);
      if (c == '(') {
        ++low;
        ++up;
      } else if (c == ')') {
        low = low > 0 ? --low: 0;
        --up;
      } else {
        low = low > 0 ? --low: 0;
        ++up;
      }
      if (up <0)
        return false;
    }
    return low<=0 && 0<=up;
  }
}
