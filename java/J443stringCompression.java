import java.util.*;

public class J443stringCompression {
  public static void main(String[] args) {
    Solution s = new Solution();
    // char[] a = {'a', 'b', 'a'};
    char[] a = {'a','a','a','b','b','a','a'};
    int res = s.compress(a);
    System.out.println(res);
    for (char c: a)
        System.out.printf("%c ", c);
    System.out.println();
  }
}
// double pointer
class Solution {
    public int compress(char[] chars) {
        int slow = 1, fast = 1;
        int n = chars.length;
        char cur = chars[0];
        int occ = 1;
        while (fast < n) {
            if (chars[fast] == cur) {
                ++occ;
            } else if (occ > 1){            // new char, and occured more than once
                String tmp = Integer.toString(occ);
                for (int idx=0, stop=tmp.length(); idx<stop; ++idx) {
                    chars[slow] = tmp.charAt(idx);
                    ++slow;
                }
                chars[slow] = chars[fast];
                ++slow;
                cur = chars[fast];
                occ = 1;
            } else {
                cur = chars[fast];
                chars[slow] = chars[fast];
                ++slow;
            }
            ++fast;
        }
        if (occ > 1) {
            String tmp = Integer.toString(occ);
            for (int idx=0, stop=tmp.length(); idx<stop; ++idx) {
                chars[slow] = tmp.charAt(idx);
                ++slow;
            }
            // chars[slow] = cur;
            // ++slow;
        }
        return slow;
    }
}
