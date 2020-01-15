import java.util.*;

public class J884uncommonWords {
  public static void main(String[] args) {
    Solution s = new Solution();

  }
}

class Solution {
  public String[] uncommonFromSentences(String A, String B) {
    String[] all = (A+" "+B).split(" ");
    Map<String, Integer> map = new HashMap<>();
    for (String s: all)
      map.put(s, map.getOrDefault(s, 0)+1);
    String[] res = new String[map.size()];
    int idx = 0;
    for (String s: map.keySet())
      if (map.get(s) == 1)
        res[idx++] = s;
    return Arrays.copyOfRange(res, 0, idx);
  }
}
