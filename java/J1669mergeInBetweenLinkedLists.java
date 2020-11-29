import java.util.*;

public class J1669mergeInBetweenLinkedLists {
  public static void main(String[] args) {
    Solution s = new Solution();

  }
}

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
  public ListNode mergeInBetween(ListNode list1, int a, int b, ListNode list2) {
    ListNode dummy = new ListNode(-1);
    dummy.next = list1;
    b = b - a;
    while (a > 1) {
      list1 = list1.next;
      --a;
    }
    ListNode rm = list1.next;
    list1.next = list2;
    while (b > 0) {
      rm = rm.next;
      --b;
    }
    while (list1.next != null) {
      list1 = list1.next;
    }
    list1.next = rm.next;
    return dummy.next;
  }
}
