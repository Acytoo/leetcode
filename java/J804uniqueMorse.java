import java.util.*;

public class J804uniqueMorse {
  public static void main(String[] args) {
    Solution s = new Solution();

  }
}

class Solution {
  public int uniqueMorseRepresentations(String[] words) {
    String[] dic = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    String[] mors = new String[words.length];
    int[] lens = new int[words.length];
    int idx=0;
    for (String word : words) {
      StringBuilder sb = new StringBuilder();
      for (char c: word.toCharArray())
        sb.append(dic[c-'a']);
      int curLen = sb.length();
      String curStr = sb.toString();
      int i=0;
      for (i=0; i<=idx; ++i)
        if (curLen == lens[i] && mors[i].equals(curStr))
          break;

      if (i > idx) {
        lens[idx] = curLen;
        mors[idx++] = curStr;
      }
    }
    return idx;
  }
}
