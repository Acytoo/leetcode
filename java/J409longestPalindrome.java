import java.util.*;

public class J409longestPalindrome {
  public static void main(String[] args) {
    Solution s = new Solution();
    String a = "civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth";
    a = "abccccdd";
    System.out.println(s.longestPalindrome(a));
  }
}

class Solution {
    public int longestPalindrome(String s) {
        int[] dict = new int['z'-'A'+1];  // ASCII A - z
        // for (char c: s.toCharArray())
            // ++dict[c-'A'];
        for (int i=0, stop=s.length(); i<stop; ++i) {
            ++dict[s.charAt(i)-'A'];
        }
        boolean odd = false;
        int res = 0;
        for (int i: dict) {
            if (i % 2 == 1) {
                odd = true;
                if (i > 1) {
                    res += i-1;
                }
            } else {
                res += i;
            }
        }
        // System.out.println(odd);
        // System.out.println(res);
        return odd? res+1:res;
    }
}
