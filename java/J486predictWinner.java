import java.util.*;

public class J486predictWinner {
  public static void main(String[] args) {
    Solution s = new Solution();

  }
}

class Solution {
  public boolean PredictTheWinner(int[] nums) {
    if (nums.length == 1)
      return true;
    m_ = new int[nums.length*nums.length];
    return getDiff(nums, 0, nums.length-1) >= 0; // 获得两者的分数差值
  }

  private int getDiff(int[] nums, int l, int r) {
    if (l == r)
      return nums[l];
    int i = l * nums.length + r;
    if (0 == m_[i])
      m_[i] = Math.max(nums[l]-getDiff(nums, l+1, r),
                       nums[r]-getDiff(nums, l, r-1));
    return m_[i];
  }

  private int[] m_;

}
