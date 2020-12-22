import java.util.*;

public class J1508rangeSumOfSortedSubarraySums {
  public static void main(String[] args) {
    Solution s = new Solution();

  }
}

class Solution2 { // 60ms
  // Brute force, using int array instead of ArrayList
  public int rangeSum(int[] nums, int n, int left, int right) {
    final int kMod = 1_000_000_007; // or convert double to int: (int) 1e9 + 7
    int sums[] = new int[n * (n + 1) >> 1];
    for (int i = 0, idx = -1, stop = nums.length; i < stop; ++i)
      for (int j = i, curSum = 0; j < stop; ++j)
        sums[++idx] = curSum += nums[j];
    Arrays.sort(sums);
    long res = 0;
    for (int i = left - 1; i < right; ++i)
      res += sums[i];
    return (int) (res % kMod);
  }
}

class Solution1 { // 182ms
  // Brute force
  public int rangeSum(int[] nums, int n, int left, int right) {
    final int kMod = 1_000_000_007; // or convert double to int: (int) 1e9 + 7
    ArrayList<Integer> sums = new ArrayList<Integer>();
    for (int i = 0, stopi = nums.length; i < stopi; ++i) {
      for (int j = i, curSum = 0; j < stopi; ++j) {
        sums.add(curSum += nums[j]);
      }
    }
    Collections.sort(sums);
    long res = 0;
    for (int i = left - 1; i < right; ++i)
      res += sums.get(i);
    return (int) (res % kMod);
  }
}