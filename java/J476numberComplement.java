import java.util.*;

public class J476numberComplement {
  public static void main(String[] args) {
    Solution s = new Solution();

  }
}

class Solution {
    // positive integer
    public int findComplement(int num) {
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
