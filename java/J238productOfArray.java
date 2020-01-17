import java.util.*;

public class J238productOfArray {
  public static void main(String[] args) {
    Solution s = new Solution();

  }
}

class Solution {
  public int[] productExceptSelf(int[] nums) {
    int n = nums.length;
    int[] res = new int[n];
    res[0] = 1;
    for (int i=1; i<n; ++i)
      res[i] = res[i-1] * nums[i-1];
    int right = 1;
    for (int i=n-2; i>=0; --i) {
      right = nums[i+1] * right;
      res[i] *= right;
    }
    return res;
  }
}
