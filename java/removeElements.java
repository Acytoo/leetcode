public class removeElements {
    public static void main(String[] args) {
	int a[] = {1,2,1,2};
	ListNode head = array2list(a, a.length);
        Solution s = new Solution();
	showList(head);
	head = s.removeElements(head, 2);
	
	
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

class Solution {
    public ListNode removeElements(ListNode head, int val) {
	//	ListNode newHead = head;
	while (head != null && head.val == val)
	    head = head.next;
	if (head == null || head.next == null)
	    return head;
	
	ListNode slow, fast;
	boolean same = false;
	slow = head;
	fast = head.next;
	while (fast != null) {
	    if (fast.val == val) {
		fast = fast.next;
		same = true;
		continue;
	    }
	    if (same) {
		slow.next = fast;
		slow = slow.next;
		fast = fast.next;
		same = false;
		continue;
	    }
	    slow = fast;
	    fast = fast.next;
	}
	if (same)
	    slow.next = fast;
	return head;
    }
}



// Definition for singly-linked list.
class ListNode {
     int val;
     ListNode next;
     ListNode(int x) { val = x; }
}
