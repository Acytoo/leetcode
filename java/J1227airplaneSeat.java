import java.util.*;

public class J1227airplaneSeat {
  public static void main(String[] args) {
    Solution s = new Solution();

  }
}

// ...
class Solution {
  public double nthPersonGetsNthSeat(int n) {
    if (n == 1)
      return 1.0;
    else
      return 0.5;
  }
}
