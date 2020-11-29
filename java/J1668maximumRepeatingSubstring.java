import java.util.*;

public class J1668maximumRepeatingSubstring {
  public static void main(String[] args) {
    Solution s = new Solution();

  }
}

class Solution {
  public int maxRepeating(String sequence, String word) {
    if (sequence.length() < word.length()) return 0;
    if (sequence.length() == word.length()) return sequence.equals(word)? 1: 0;
    String s = new String(word);
    for (int res = 0;; ++res) {
      if (sequence.indexOf(s) == -1) return res;
      s += word;
    }
  }
}
