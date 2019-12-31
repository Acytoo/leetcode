import java.util.*;

public class J1299replace {
  public static void main(String[] args) {
    Solution s = new Solution();

  }
}

class Solution {
  public int[] replaceElements(int[] arr) {
    // DP, res[n] = Math.max(res[n+1], arr[n+1])
    // 1 <= arr.length <= 10^4
    // 1 <= arr[i] <= 10^5
    int n = arr.length;
    int[] res = new int[n];
    res[--n] = -1;

    while (--n >= 0) {
      res[n] = Math.max(res[n+1], arr[n+1]);
    }
    return res;

  }
}
