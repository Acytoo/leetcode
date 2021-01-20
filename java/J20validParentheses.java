import java.util.*;

public class J20validParentheses {
  public static void main(String[] args) {
    Solution s = new Solution();

  }
}

class Solution {
  public boolean isValid(String s) {
    Stack<Character> st = new Stack<>();
    for (int i = 0, n = s.length(); i < n; ++i) {
      final char c = s.charAt(i);
      if (c == '(' || c == '[' || c == '{') {
        st.push(c);
      } else {
        if (st.isEmpty())
          return false;
        if (c == ')') {
          if (st.peek() != '(')
            return false;
        } else {
          if (st.peek() != (c - 2))
            return false;
        }
        st.pop();
      }
    }
    return st.isEmpty();
  }
}
