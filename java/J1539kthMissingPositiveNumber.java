import java.util.*;

public class J1539kthMissingPositiveNumber {
  public static void main(String[] args) {
    Solution s = new Solution();

  }
}

class Solution {
  public int findKthPositive(int[] arr, int k) {
    final int n = arr.length;
    int i = 0, num = 1;
    while (i < n && k > 0) {
      if (num == arr[i]) {
        ++i;
        ++num;
      } else {
        --k;
        ++num;
      }
    }
    return i == n? num + k - 1: num - 1;
  }
}
