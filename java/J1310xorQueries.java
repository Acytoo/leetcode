import java.util.*;

public class J1310xorQueries {
  public static void main(String[] args) {
    Solution s = new Solution();

  }
}


class Solution {
  public int[] xorQueries(int[] arr, int[][] queries) {
    int[] xor = new int[arr.length + 1];
    for (int i = 0; i < arr.length; i++) {
      xor[i + 1] = xor[i] ^ arr[i];
    }
    int[] result = new int[queries.length];
    for (int i = 0; i < queries.length; i++) {
      result[i] = xor[queries[i][1] + 1] ^ xor[queries[i][0]];
    }
    return result;
  }
}

class Solution1 {
  public int[] xorQueries(int[] a, int[][] q) {
    int n = q.length;
    int[] res = new int[n];
    for (int i=0; i<n; ++i) {
      int tmp = 0;
      for (int j=q[i][0]; j<=q[i][1]; ++j)
        tmp = tmp ^ a[j];
      res[i] = tmp;
    }
    return res;
  }
}
