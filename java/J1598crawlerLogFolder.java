import java.util.*;

public class 1598crawlerLogFolder {
  public static void main(String[] args) {
    Solution s = new Solution();

  }
}

class Solution {
  public int minOperations(String[] logs) {
    int res = 0;
    for (String log: logs)
      if (log.charAt(1) == '/')
        continue;
      else if (log.charAt(1) == '.')
        res = res == 0? res: res - 1;
      else
        ++res;
    return res;
  }
}
