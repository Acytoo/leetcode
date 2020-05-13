import java.util.*;

public class J402removeKDigits {
  public static void main(String[] args) {
    Solution s = new Solution();
    String a = "13245";
    String res = s.removeKdigits(a, 2);
    System.out.println(res);
  }
}
// 43215, 1 -> 3215
// 43215, 2 -> 215
// 34215, 3 -> 15
// 43215, 4 -> 1

// 13245, 1 -> 1245
// 13245, 2 -> 124
// 13245, 3 -> 12
// 13245, 4 -> 1
// 从高数位开始扫描，每删去一位，--k，在k允许的情况下，尽量从小到大排列

class Solution {
  public String removeKdigits(String num, int k) {
    int n = num.length();
    if (k == n) return "0";

    Stack<Character> stack = new Stack<>();
    int i = 0;
    while (i < n) {
      while (k>0 && !stack.isEmpty() && num.charAt(i) < stack.peek()) {
        stack.pop();
        --k;
      }
      stack.push(num.charAt(i));
      ++i;
    }
    // k != 0 -> 22222222222
    while (k>0) {
      stack.pop();
      --k;
    }
    StringBuilder sb = new StringBuilder();
    while (!stack.isEmpty()) {
      sb.append(stack.pop());
    }
    sb.reverse();

    while (sb.length()>1  && sb.charAt(0)=='0') {
      sb.deleteCharAt(0);
    }
    return sb.toString();
  }
}
