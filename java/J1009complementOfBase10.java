import java.util.*;

public class J1009complementOfBase10 {
  public static void main(String[] args) {
    Solution s = new Solution();

  }
}

// Same question: 476. number complement
class Solution {
  public int bitwiseComplement(int num) {
    if (num == 0)
      return 1;
    int[] bin = new int[32];
    int idx = 0;
    while (num > 0) {
      bin[idx] =  num & 1;
      num >>= 1;
      ++idx;
    }
    int res = 0;
    boolean start = false;
    for (int i=idx-1; i>=0; --i) {
      int tmp = bin[i] ^ 1;
      if (tmp != 0 || start){
        start = true;
        res <<= 1;
        res = res | tmp;
      }
    }
    return res;
  }
}
