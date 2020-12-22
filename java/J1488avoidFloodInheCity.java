import java.util.*;

public class J1488avoidFloodInheCity {
  public static void main(String[] args) {
    Solution s = new Solution();

  }
}

class Solution {
  public int[] avoidFlood(int[] rains) {
    final int n = rains.length;
    int res[] = new int [n];
    Arrays.fill(res, -1);
    Map<Integer, Integer> full = new HashMap<>();
    TreeSet<Integer> dry = new TreeSet<>();
    for (int i = 0; i < n; ++i) {
      final int lake = rains[i];
      if (lake > 0) {
        if (full.containsKey(lake)){
          Integer day = dry.higher(full.get(lake));
          if (day == null) return new int[0];
          res[day] = lake;
          dry.remove(day);
        }
        full.put(lake, i);
      } else { // no rain that day
        res[i] = 1;
        dry.add(i);
      }
    }
    return res;
  }
}