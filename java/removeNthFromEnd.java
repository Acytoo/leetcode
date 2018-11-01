public class hello {
    public static void main(String[] args) {
	Solution s = new Solution();
	//	int[] a = {1,2,3,1};//res = 4
	//	int[] b = {2,7,9,3,1};//res = 12
	int a = 5;
	int b = -1;
	System.out.println(s.divide(Integer.MIN_VALUE,1));
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

