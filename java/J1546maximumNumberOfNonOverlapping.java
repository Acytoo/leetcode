import java.util.*;

public class J1546maximumNumberOfNonOverlapping {
  public static void main(String[] args) {
    Solution s = new Solution();

  }
}

class Solution {
  public int maxNonOverlapping(int[] nums, int target) {
    Map<Integer, Integer> map = new HashMap<>();
    int n = nums.length, sum = 0, res = 0;
    map.put(0, -1);

    for (int i = 0; i < n; i++) {
      sum += nums[i];
      if (map.containsKey(sum - target)) {
        res++;
        map.clear();
      }
      map.put(sum , i);
    }
    return res;
  }
}

class Solution1 {
  public int maxNonOverlapping(int[] nums, int target) {
    final int n = nums.length;
    int [] dp = new int[n + 1];
    HashMap<Integer, Integer> sum_idx = new HashMap<>();
    sum_idx.put(0, -1);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      sum += nums[i];
      final int t = sum - target;
      dp[i + 1] = dp[i];
      if (sum_idx.containsKey(t))
        dp[i + 1] = Math.max(dp[i], dp[sum_idx.get(t) + 1] + 1);
      sum_idx.put(sum, i);
    }
    return dp[n];
  }
}
