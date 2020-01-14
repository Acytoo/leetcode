import java.util.*;

public class J556nextGreaterIII {
  public static void main(String[] args) {
    Solution s = new Solution();

  }
}
// 32 bit integer , max 10 digits
class Solution {
  public int nextGreaterElement(int n) {
    int[] digits = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    int digit = n % 10;
    digits[0] = digit;
    int idx = 1;
    n /= 10;
    int i = 0;
    while (n > 0) {
      digit = n % 10;

      for (i=0; i<idx; ++i)
        if (digit < digits[i])
          break;

      if (i < idx)
        break;

      digits[idx] = digit;
      ++idx;

      n /= 10;
    }
    if (n == 0)
      return -1;
    long res = n / 10;
    res = res*10 + digits[i];
    digits[i] = digit;
    for (int j=0; j<idx; ++j)
      res = res * 10 + digits[j];
    return res > (long)Integer.MAX_VALUE ? -1: (int)res;
  }
}
