import java.util.*;

class ListNode {
  int val;
  ListNode next;
  ListNode(int x) { val = x; }
}

class Solution {
  public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
    ListNode root = new ListNode(-1);
    ListNode p = root;
    while (l1 != null && l2 != null) {
      if (l1.val < l2.val) {
        p.next = l1;
        l1 = l1.next;
      } else {  // l1 = l1 || l2 < l1
        p.next = l2;
        l2 = l2.next;
      }
      p = p.next;  // move the pointer
    }
    // if l1 or l2 still has next
    if (l1 != null) p.next = l1;
    if (l2 != null) p.next = l2;
    return root.next;
  }
}

public class J21mergeTwoSortedLists {
  public static void main(String[] args) {
  }
}
