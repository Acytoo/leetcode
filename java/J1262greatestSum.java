import java.util.*;

public class J1262greatestSum {
  public static void main(String[] args) {
    Solution s = new Solution();

  }
}

// java Array.sort()不支持int等基本类型的降序排列
class Solution1 {
  public int maxSumDivThree(int[] nums) {
    int[] dp = new int[]{0, Integer.MIN_VALUE, Integer.MIN_VALUE};
    for (int num: nums) {
      int[] dp2 = new int[3];
      for (int i=0; i<3; ++i)
        dp2[(i+num)%3] = Math.max(dp[(i+num)%3], dp[i]+num);
      dp = dp2;
    }
    return dp[0];
  }
}
