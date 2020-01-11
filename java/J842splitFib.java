import java.util.*;

public class J842splitFib {
  public static void main(String[] args) {
    Solution s = new Solution();
    String a = "123456";
    List<Integer> res = s.splitIntoFibonacci(a);

  }
}

// DFS，减枝加速
class Solution {
  public List<Integer> splitIntoFibonacci(String S) {
    s_ = S.toCharArray();
    n_ = s_.length;
    res_ = new ArrayList<Integer>();
    dfs(0);
    return res_;
  }

  private boolean dfs(int pos) {
    if (pos == n_)
      return res_.size() >= 3;
    int maxLen = s_[pos] == '0'? 1: 10;
    long num = 0;
    for (int i=pos; i<Math.min(pos+maxLen, n_); ++i) {
      num = num*10 + (s_[i]-'0');
      if (Integer.MAX_VALUE < num)
        break;
      if (2 <= res_.size()) {
        long sum = res_.get(res_.size()-1);
        sum += res_.get(res_.size()-2);
        if (sum < num)
          break;
        else if (num < sum)
          continue;
      }
      res_.add((int)num);
      if(dfs(i+1))
        return true;
      res_.remove(res_.size()-1);
    }
    return false;
  }
  private char[] s_;
  private int n_;
  List<Integer> res_;
}
