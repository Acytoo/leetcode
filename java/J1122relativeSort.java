import java.util.*;

public class J1122relativeSort {
  public static void main(String[] args) {
    Solution s = new Solution();

  }
}

// 多指针，指向后面元素的最大，最小，
class Solution {
  public int[] relativeSortArray(int[] a1, int[] a2) {
    int n1 = a1.length, n2 = a2.length;
    int[] res = new int [n1];
    int p = n1 - n2;
    boolean[] taken = new boolean [n1];
    int idx = 0;
    // O(m * n)
    for (int i=0; i<n2; ++i) {
      int j=0;
      for (; j<n1; ++j) {
        if (a2[i] == a1[j]) {
          res[idx++] = a2[i];
          taken[j] = true;
        }
      }
    }
    int start = idx;
    for(int i=0; i<n1; ++i)
      if (!taken[i])
        res[idx++] = a1[i];
    Arrays.sort(res, start, n1);
    return res;
  }
}
