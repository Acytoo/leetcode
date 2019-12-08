import java.lang.Math;

public class J1189MaximumBalloons {
  public static void main(String[] args) {
    Solution s = new Solution();
    System.out.println(s.maxNumberOfBalloons("ballolnnno"));
  }
}


class Solution {
  public int maxNumberOfBalloons(String text) {
    int i = 0, stop = text.length();
    if (stop < 7) return 0;
    int[] counting = new int[5];
    while (i < stop) {
      char c = text.charAt(i);
      switch (c) {
        case 'b': ++counting[0]; break;
        case 'a': ++counting[1]; break;
        case 'l': ++counting[2]; break;
        case 'o': ++counting[3]; break;
        case 'n': ++counting[4]; break;
        default: break;
      }
      ++i;
    }
    counting[2] /= 2;
    counting[3] /= 2;
    int res = Integer.MAX_VALUE;
    for (int x: counting) {
      res = Math.min(res, x);
    }
    return res;
  }
}
