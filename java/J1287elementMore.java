import java.util.*;

public class J1287elementMore {
  public static void main(String[] args) {
    Solution s = new Solution();
    int[] a = {1, 2, 3, 3};
    int res = s.findSpecialInteger(a);
    System.out.println(res);
  }
}

class Solution {
  public int findSpecialInteger(int[] arr) {
    int threshold = (int)Math.ceil(arr.length / 4.0);
    int curNum = arr[0];
    int i = 0, n = threshold;
    while (n >= 0) {
      if (i+threshold >= arr.length)
        return arr[i];
      if (arr[i] != curNum) {
        curNum = arr[i];
        n = threshold;
      } else {
        ++i;
        --n;
      }
    }
    return curNum;
  }
}
