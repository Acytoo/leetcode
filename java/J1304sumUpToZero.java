import java.util.*;

public class J1304sumUpToZero {
  public static void main(String[] args) {
    Solution s = new Solution();
    int[] res = s.sumZero(6);
    for (int i: res)
      System.out.printf("%d ", i);
    System.out.println();
  }
}

class Solution {
  public int[] sumZero(int n) {
    int rem = n % 2, stop = n / 2, i = 0;
    int[] res = new int[n];
    --n;
    while (i < stop) {
      int tmp = i+1;
      res[i] = tmp;
      res[n-i] = -tmp;
      ++i;
    }
    if (rem == 1)
      res[stop] = 0;
    return res;
  }
}
