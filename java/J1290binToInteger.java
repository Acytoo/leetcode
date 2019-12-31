import java.util.*;

public class J1290binToInteger {
  public static void main(String[] args) {
    Solution s = new Solution();

  }
}

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
  public int getDecimalValue(ListNode head) {

    while (head!=null && head.val==0)
      head = head.next;
    if (head == null)
      return 0;

    int res = 1;
    head = head.next;

    while (head != null) {
      res <<= 1;
      res += head.val;
      head = head.next;
    }
    return res;
  }
}
