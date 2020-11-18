import java.util.*;

public class J1647minimumDeletionsToMakeUnique {
  public static void main(String[] args) {
    Solution s = new Solution();

  }
}

class Solution {
  public int minDeletions(String s) {
    int chars[] = new int['z' + 1];
    for (char c: s.toCharArray()) ++chars[c];
    HashSet<Integer> freq = new HashSet<>();
    int res = 0;
    for (char c = 'a'; c <= 'z'; ++c) {
      while (freq.contains(chars[c]) && chars[c] > 0) {
        --chars[c];
        ++res;
      }
      if (chars[c] != 0) freq.add(chars[c]);
    }
    return res;
  }
}
