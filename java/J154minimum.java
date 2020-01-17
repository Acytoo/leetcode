import java.util.*;

public class J153minimum {
  public static void main(String[] args) {
    Solution s = new Solution();

  }
}

class Solution {
  public int findMin(int[] nums) {
    int res = nums[nums.length-1];
    for (int i=nums.length-2; i>=0; --i) {
      if (nums[i] <= res)
        res = nums[i];
      else
        break;
    }
    return res;
  }
}
