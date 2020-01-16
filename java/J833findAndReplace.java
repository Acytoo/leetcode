import java.util.*;

public class J833findAndReplace {
  public static void main(String[] args) {
    Solution s = new Solution();

  }
}

class Solution {
  public String findReplaceString(String S, int[] indexes, String[] sources, String[] targets) {
    StringBuilder res = new StringBuilder(S);
    int change = 0;
    int n = S.length();
    int[] sortedIdx = indexes.clone();
    Arrays.sort(sortedIdx);

    for (int j: sortedIdx)
      for (int i=0; i<indexes.length; ++i)
        if (j == indexes[i]) {
          int startIdx = indexes[i], endIdx = startIdx + sources[i].length();
          if (S.substring(startIdx, endIdx).equals(sources[i])) {
            res.replace(startIdx+change, endIdx+change, targets[i]);
            change += targets[i].length() - sources[i].length();
          }
        }
    return res.toString();
  }
}
