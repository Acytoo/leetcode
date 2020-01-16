import java.util.*;

public class J1234Template {
  public static void main(String[] args) {
    Solution s = new Solution();

  }
}

// 这应该是一道medium，甚至是easy的题目。
// 每次扫描一层，将这一层可以储存的水储存起来，累加得出结果
// 速度非常慢
class Solution {
  public int trap(int[] height) {

    int lowest = Integer.MAX_VALUE, highest = 0;
    for (int tmp: height) {
      if (tmp < lowest)
        lowest = tmp;
      else if (highest < tmp)
        highest = tmp;
    }

    int cur = 0;
    int res = 0;
    int n = height.length;

    for (int level = lowest; level <= highest; ++level) {
      int i=0;
      cur = 0;
      while (i<n && height[i] <= level) ++i;

      while (++i < n) {
        if (level < height[i]) {
          res += cur;
          cur = 0;
        } else {
          ++cur;
        }
      }
    }
    return res;
  }
}
