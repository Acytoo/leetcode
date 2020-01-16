import java.util.*;

public class J961repeatedEle {
  public static void main(String[] args) {
    Solution s = new Solution();

  }
}

// N+1 element
class Solution {
  public int repeatedNTimes(int[] A) {
    int[] dic = new int[10000];
    for (int a: A)
      if (++dic[a] > 1)
        return a;
    return -1;
  }
}

class Solution1 {
  public int repeatedNTimes(int[] A) {
    int times = A.length / 2;
    int[] dic = new int[10000];
    for (int a: A)
      if (times <= ++dic[a])
        return a;
    return -1;
  }
}
