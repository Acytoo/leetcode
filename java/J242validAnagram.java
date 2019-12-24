import java.util.*;

public class J242validAnagram {
    public static void main(String[] args) {
        Solution s = new Solution();

    }
}

class Solution {
    public boolean isAnagram(String s, String t) {
        int n = s.length(), m = t.length();
        if (n != m)
            return false;
        int[] ss = new int[26];
        int[] tt = new int[26];
        for (int i=0; i<n; ++i) {
            ++ss[s.charAt(i) - 'a'];
            ++tt[t.charAt(i) - 'a'];
        }
        for (int i=0; i<26; ++i)
            if (ss[i] != tt[i])
                return false;
        return true;
    }
}
