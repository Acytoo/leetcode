import java.util.*;
import java.lang.Math;

public class J342powerOfFour {
  public static void main(String[] args) {
    Solution s = new Solution();

  }
}

class Solution {
    public boolean isPowerOfFour(int num) {
        // max signed 32 int: 2,147,483,647 = 2^31-1 = 2*(2^2)^15-1 = 4^15*2-1
        for (int i=0; i<16; ++i)
            if (num == (int)Math.pow(4, i))
                return true;
        return false;
    }
}
