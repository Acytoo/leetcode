import java.util.*;

public class J383ransomNote {
  public static void main(String[] args) {
    Solution s = new Solution();
    String a = "leetcode", b = "leecasdctodade";
    System.out.println(s.canConstruct(a, b));

  }
}

// faster olution from leetcode
class Solution1 {
    public boolean canConstruct(String ransomNote, String magazine) {
        int r = ransomNote.length();
        int m = magazine.length();

        if(r > m){
            return false;
        }
        int[] list = new int[26];
        int index = 0;

        for(char c : ransomNote.toCharArray()){
            index = magazine.indexOf(c, list[c - 'a']);
            if(index < 0){
                return false;
            }
            list[c - 'a'] = index + 1;
        }
        return true;
    }
}


class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        int[] dict = new int[26];
        for (int i=0, stop=magazine.length(); i<stop; ++i)
            ++dict[magazine.charAt(i)-'a'];
        for (int i=0, stop=ransomNote.length(); i<stop; ++i) {
            if (--dict[ransomNote.charAt(i) - 'a'] < 0)
                return false;
        }
        // for (int i: dict)
        // if (i < 0)
        // return false;
        return true;
    }
}
