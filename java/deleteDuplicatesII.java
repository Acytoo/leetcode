public class hello {
    public static void main(String[] args) {
	int a[] = {1,1,1, 2,2, 3,4,5,6,6};
	ListNode head = array2list(a, a.length);
        Solution s = new Solution();
	showList(head);
	head = s.deleteDuplicates(head);
	showList(head);

    }
    public static void showList(ListNode head) {
	ListNode dis = head;
	if (head == null)
	    System.out.print("Empty list");
	while (dis != null) {
	    System.out.printf("%d ", dis.val);
	    dis = dis.next;
	}
	System.out.println();
    }
    public static ListNode array2list(int[] a, int n) {
	ListNode head = new ListNode(a[0]), tail;
	head.next = null;
	tail = head;
	for (int i=1; i < n; i++) {
	    ListNode newNode = new ListNode(a[i]);
	    tail.next = newNode;
	    newNode.next = null;
	    tail = tail.next;
	}
	return head;
    }

}


// Definition for singly-linked list.
class ListNode {
     int val;
     ListNode next;
     ListNode(int x) { val = x; }
}
/*
  head, pre, slow, fast, null 
 pre == null || not null
 */
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
	if (head == null || head.next == null)
	    return head;
    
	ListNode pre, slow, fast;
	ListNode fakeHead = new ListNode(0);
	fakeHead.next = head;
	pre = fakeHead;
	slow = head;
	fast = head.next;
	boolean same = false;

	while (fast != null) {
	    if (slow.val == fast.val) {
		fast = fast.next;
		if (fast == null) {
		    pre.next = null;
		    break;
		}
		same = true;
		continue;
	    }
	    if (same) {
		pre.next = fast;
		slow = fast;
		fast = fast.next;
		same = false;
		continue;
	    }
	    pre = slow;
	    slow = fast;
	    fast = fast.next;
	}
	return fakeHead.next;
    }
}
