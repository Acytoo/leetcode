import java.util.*;

public class J405decToHex {
  public static void main(String[] args) {
    Solution s = new Solution();
    System.out.println(s.toHex(-123));
  }
}

// another solution from leetcode
class Solution1 {
    char[] map = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
    public String toHex(int num) {
        if(num == 0) return "0";
        String result = "";
        while(num != 0){
            result = map[(num & 15)] + result;
            num = (num >>> 4);
        }
        return result;
    }
}

// my stupid solution, dec -> bin -> hex
class Solution {
    public String toHex(int num) {
        if (num == 0)
            return "0";

        int[] bin = new int[32];
        boolean neg = num < 0;
        if (neg) {
            num = -num;
            int carry = 1;
            for (int i=0; i<32; ++i) {
                int tmp = ((num & 1) ^ 1);
                bin[31-i] = tmp ^ carry;
                carry = tmp & carry;
                num >>= 1;
            }
        } else {
            for (int i=0; i<32; ++i) {
                bin[31-i] = (num & 1);
                num >>= 1;
            }
        }

        StringBuilder res = new StringBuilder();
        for (int i=0; i<=7; ++i) {
            // each digit = i*4+0, i*4+1, i*4+2, i*4+3
            int dec = 0;
            for (int j=0; j<=3; ++j) {
                dec <<= 1;
                dec = dec | bin[i*4+j];
            }
            if (dec < 10)
                res.append((char)(dec+'0'));
            else
                res.append((char)(dec-10+'a'));
        }
        while (res.charAt(0) == '0')
            res.deleteCharAt(0);
        return res.toString();
    }
}
