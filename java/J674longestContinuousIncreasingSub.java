import java.util.*;

public class J674longestContinuousIncreasingSub {
  public static void main(String[] args) {
    Solution s = new Solution();
    int[] a = {1, 2,50, 3, 4, 5, 6, 7, 8, 8, 8};
    int res = s.findLengthOfLCIS(a);
    System.out.println(res);

  }
}
class Solution {
  public int findLengthOfLCIS(int[] nums) {
    int n = nums.length;
    if (n < 2) return n;

    int res = 1, cur = 1;

    for (int i=0, stop=n-1; i<stop; ) {
      if (nums[i] < nums[++i]) {
        ++cur;
      } else {
        res = Math.max(res, cur);
        cur = 1;
      }
    }
    res = Math.max(res, cur);
    return res;
  }
}
