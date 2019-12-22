import java.util.*;

public class J97interleavingString {
  public static void main(String[] args) {
    Solution s = new Solution();
    String a = "abc", b = "sdf", c = "asbcdf";
    System.out.println(s.isInterleave(a, b, c));
  }
}

// Thanks to basketwang
class Solution {
  public boolean isInterleave(String s1, String s2, String s3) {

    int l1 = s1.length(), l2 = s2.length(), l3 = s3.length();
    if (l3 != l1 + l2) return false;

    boolean[][] match = new boolean[l1+1][l2+1];
    match[0][0] = true;
    for (int i=0; i<l3; ++i) {
      // l1cur: maximum ***length*** of s1 when s3 is [0:i]. Length, not index
      for (int l1cur=0, l1stop=i+1; l1cur<=l1 && l1cur<=l1stop; ++l1cur) {
        int l2cur = l1stop - l1cur;
        if (l2cur>l2) continue;  // false
        if ( ( l1cur>0 && s3.charAt(i)==s1.charAt(l1cur-1) && match[l1cur-1][l2cur] ) ||
             (l2cur>0 && s3.charAt(i)==s2.charAt(l2cur-1) && match[l1cur][l2cur-1] ) )
          match[l1cur][l2cur] = true;
      }
    }
    return match[l1][l2];
  }
}
