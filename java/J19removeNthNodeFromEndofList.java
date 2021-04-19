
public class J19removeNthNodeFromEndofList {
  public static void main(String[] args) {
	Solution s = new Solution();
  }
}


// Definition for singly-linked list.
public class ListNode {
  int val;
  ListNode next;
  ListNode(int x) { val = x; }
}

class Solution {
  public ListNode removeNthFromEnd(ListNode head, int n) {
	if (head == null || n == 0)
      return head;
	ListNode fast, slow;
	fast = head;
	while (n > 0) {
      fast = fast.next;
      n--;
	}
	// If at this time, fast = null, then we return null
	if (fast == null)
      return head.next;
	slow = head;
	while (fast.next != null) {
      slow = slow.next;
      fast = fast.next;
	}
	slow.next = slow.next.next;
	return head;
  }
}

