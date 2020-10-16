import java.util.*;

public class J1470shuffleTheArray {
  public static void main(String[] args) {
    Solution s = new Solution();

  }
}

class Solution {
  public int[] shuffle(int[] nums, int n) {
    int nn = nums.length;
    int[] res = new int [nn];
    for (int i = 0, j = -1; i < n; ++i) {
      res[++j] = nums[i];
      res[++j] = nums[i + n];
    }
    return res;
  }
}
