import java.util.*;

public class J1431kidsWithTheGreatestNumberOfCandies {
  public static void main(String[] args) {
    Solution s = new Solution();

  }
}

class Solution {
  public List<Boolean> kidsWithCandies(int[] candies, int extraCandies) {
    int m = candies[0];
    for (int i = 1, n = candies.length; i < n; ++i)
      if (m < candies[i])
        m = candies[i];
    List<Boolean> res = new LinkedList<>();
    for (int can: candies)
      if (can + extraCandies >= m)
        res.add(true);
      else
        res.add(false);
    return res;
  }
}
