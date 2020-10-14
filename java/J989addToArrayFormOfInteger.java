import java.util.*;

public class J989addToArrayFormOfInteger {
  public static void main(String[] args) {
    Solution s = new Solution();
    int[] A = {1,2,3,4};
    int K = 45;
    List<Integer> res = s.addToArrayForm(A, K);
    for (Integer a: res)
      System.out.println(a.intValue());
  }
}

class Solution {
  public List<Integer> addToArrayForm(int[] A, int K) {
    LinkedList<Integer> res = new LinkedList<Integer>();
    int i = A.length - 1, carry = 0;
    while (K > 0 && i >= 0) {
      K += A[i];
      res.addFirst(K % 10);
      K /= 10;
      --i;
    }
    while (K > 0) {
      res.addFirst(K % 10);
      K /= 10;
    }
    while (i >= 0) res.addFirst(A[i--]);
    return res;
  }
}

class Solution1 {
  public List<Integer> addToArrayForm(int[] A, int K) {
    int n = A.length - 1;
    // List<Integer> res = new ArrayList<Integer>();
    // better when adding element at the front or end
    List<Integer> res = new LinkedList<Integer>();
    int carry = 0;
    while (n >= 0 || K > 0) {
      int digit = K % 10;
      K /= 10;
      int sum_digit = digit + carry;
      if (n >= 0) sum_digit += A[n];
      --n;
      if (sum_digit > 9) {
        sum_digit -= 10;
        carry = 1;
      } else {
        carry = 0;
      }
      res.add(sum_digit);
    }
    if (carry >= 1) res.add(1);
    Collections.reverse(res);
    return res;
  }
}
