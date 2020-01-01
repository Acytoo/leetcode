import java.util.*;

public class J394decodingString {
  public static void main(String[] args) {
    Solution s = new Solution();
    String a = "3[a2[c]]";
    // String a = "3[a]";
    String res = s.decodeString(a);
    System.out.println(res);
  }
}

class Solution {
    public String decodeString(String s) {
        sb_ = new StringBuilder(s);
        length_ = s.length();
        int i[] = new int[1];
        i[0] = 0;
        return decodeString(i);
    }
    private String decodeString(int[] i) {
        int k = 0;
        StringBuilder res = new StringBuilder();

        while (i[0] < length_) {
            if (Character.isDigit(sb_.charAt(i[0]))) {
                while (Character.isDigit(sb_.charAt(i[0]))) {
                    k = k * 10 + sb_.charAt(i[0]) - '0';
                    ++i[0];
                }
                ++i[0];
                // '[', then another s
                String ress = decodeString(i);
                while (k > 0) {
                    res.append(ress);
                    --k;
                }
            } else if (Character.isLetter(sb_.charAt(i[0]))) {
                res.append(sb_.charAt(i[0]));
                ++i[0];
            } else {            // ']'
                ++i[0];
                return res.toString();
            }
        }
        return res.toString();
    }
    private StringBuilder sb_;
    private int length_;
}
