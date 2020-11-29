import java.util.*;

public class J1672richestCustomerWealth {
  public static void main(String[] args) {
    Solution s = new Solution();

  }
}

class Solution {
  public int maximumWealth(int[][] accounts) {
    int res = 0;
    for (int[] account: accounts)
      res = Math.max(res, Arrays.stream(account).sum());
    return res;
  }
}
