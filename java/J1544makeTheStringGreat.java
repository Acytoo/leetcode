import java.util.*;

public class J1544makeTheStringGreat {
  public static void main(String[] args) {
    Solution s = new Solution();

  }
}

class Solution {
  public String makeGood(String s) {
    LinkedList<Character> ll = new LinkedList<>();
    ll.addLast(s.charAt(0));
    for (int i = 1, n = s.length(); i < n; ++i)
      if (!ll.isEmpty() && (ll.getLast() ^ s.charAt(i)) == 32)
        ll.removeLast();
      else
        ll.addLast(s.charAt(i));
    String res = new String();
    while (!ll.isEmpty()) {
      res += ll.getFirst();
      ll.removeFirst();
    }
    return res;
  }
}

class Solution1 {
  public String makeGood(String s) {
    StringBuffer sb = new StringBuffer();
    int index = -1;
    for (int i = 0; i < s.length(); i++) {
      char ch = s.charAt(i);
      if (sb.length() > 0 &&
          Character.toLowerCase(sb.charAt(index)) == Character.toLowerCase(ch) &&
          sb.charAt(index) != ch) {
        sb.deleteCharAt(index);
        --index;
      } else {
        sb.append(ch);
        ++index;
      }
    }
    return sb.toString();
  }
}
