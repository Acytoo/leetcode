import java.util.*;

public class J953alienDic {
  public static void main(String[] args) {
    Solution s = new Solution();

  }
}

class Solution {
  public boolean isAlienSorted(String[] words, String order) {
    int n = words.length-1;
    if (n == 0)
      return true;

    int[] dic = new int[26];
    for (int i=0; i<26; ++i)
      dic[order.charAt(i)-'a'] = i;

    for (int i=0; i<n;)
      if (unSorted(words[i], words[++i], dic))
        return false;
    return true;
  }
  private boolean unSorted(String a, String b, int[] dic) {
    int m = a.length(), n = b.length();
    int stop = m < n? m: n;
    for (int i=0; i< stop; ++i)
      if (a.charAt(i) != b.charAt(i))
        return dic[b.charAt(i)-'a'] < dic[a.charAt(i)-'a'];
    return n < m;
  }
}
