import java.util.*;

public class J520detectCapital {
  public static void main(String[] args) {
    Solution s = new Solution();
    String a = "DADADd";
    System.out.println(s.detectCapitalUse(a));
  }
}

class Solution {
    public boolean detectCapitalUse(String word) {
        int n = word.length();
        if (n == 1)
            return true;
        boolean firCap = word.charAt(0) < 'a';
        if (n == 2)
            if (firCap)
                return true;
            else                // not a capital start
                return word.charAt(1) >= 'a';
        // n >= 3, 2.cap == rest.cap
        if (firCap) {
            boolean secCap = word.charAt(1) < 'a';
            for (int i=2; i<n; ++i)
                if ((word.charAt(i) < 'a') != secCap)
                    return false;
        } else {
            for (int i=1; i<n; ++i)
                if (word.charAt(i) < 'a')
                    return false;
        }
        return true;
    }
}
