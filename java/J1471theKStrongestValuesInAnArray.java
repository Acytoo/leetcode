import java.util.*;

public class J1471theKStrongestValuesInAnArray {
  public static void main(String[] args) {
    Solution s = new Solution();

  }
}

// Solution from leetcode
class Solution {
  public int[] getStrongest(int[] arr, int k) {
    int min = Integer.MAX_VALUE, max = Integer.MIN_VALUE;
    for (int i : arr) {
      min = Math.min(i, min);
      max = Math.max(i, max);
    }
    int[] countArr = new int[max - min + 1];
    for (int i : arr) ++countArr[i - min];

    int idx = 0;
    for (int i = 0; i < countArr.length; ++i) {
      while (countArr[i] > 0) {
        arr[idx++] = i + min;
        --countArr[i];
      }
    }
    // Now arr is sorted
    int[] result = new int[k];
    int n = arr.length, l = 0, r = n - 1, median = (n - 1) / 2, writer = 0;

    while (l <= r) {
      if (Math.abs(arr[l] - arr[median]) > Math.abs(arr[r] - arr[median])) {
        result[writer++] = arr[l++];
      } else {
        result[writer++] = arr[r--];
      }
      --k;
      if (k == 0) break;
    }
    return result;
  }
}

class Solution1 {
  public int[] getStrongest(int[] arr, int k) {
    final int n = arr.length;
    Arrays.sort(arr);
    int[] res = new int[k];
    final int med = arr[(n - 1) >> 1];
    int l = 0, r = n - 1;
    for (int i = 0; i < k; ++i) {
      if (Math.abs(arr[l] - med) > Math.abs(arr[r] - med)) {
        res[i] = arr[l];
        ++l;
      } else {
        res[i] = arr[r];
        --r;
      }
    }
    return res;
  }
}