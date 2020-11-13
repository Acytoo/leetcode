import java.util.*;

public class J1646getMaximumInGeneratedArray {
  public static void main(String[] args) {
    Solution s = new Solution();

  }
}


class Solution {
  public int getMaximumGenerated(int n) {
    if (n == 0) return 0;
    if (n <= 2) return 1;
    int[] nums = new int[n + 1];
    nums[0] = 0;
    nums[1] = nums[2] = 1;
    int res = 2;
    for (int i = 2; i <= n; ++i)
      if ((i & 1) == 1) {
        nums[i] = nums[i >> 1] + nums[(i >> 1) + 1];
        res = Math.max(res, nums[i]);
      } else {
        nums[i] = nums[i >> 1];
      }
    return res;
  }
}
