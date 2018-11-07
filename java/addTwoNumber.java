public class template {
    public static void main(String[] args) {
	int[] l1 = {2,4,3}, l2 = {5,6,4};
	ListNode arr1 = array2list(l1, l1.length);
	ListNode arr2 = array2list(l2, l2.length);
        Solution s = new Solution();
	//	showList(head);
	
	
	ListNode res = s.addTwoNumbers(arr1, arr2);
	
	showList(res);

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
    StringBuilder sbRes;
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
	sbRes = new StringBuilder();
	int insertPos = 0;
	int carry = 0;
	while (l1 != null || l2 != null || carry != 0) {
	    int n1 = l1 == null ? 0 : l1.val;
	    int n2 = l2 == null ? 0 : l2.val;
	    int temp = n1 + n2 + carry;
	    if (temp > 9) {
		temp -= 10;
		carry = 1;
	    }
	    else
		carry = 0;
	    sbRes.append(temp);
	    l1 = l1 == null ? null : l1.next;
	    l2 = l2 == null ? null : l2.next;
	    insertPos++;
	}
	ListNode head = new ListNode((byte)sbRes.charAt(0) - '0');
	head.next = null;
	ListNode startNode = head;
	int i=1;
	while (i < sbRes.length()) {
	    ListNode newNode = new ListNode((byte)sbRes.charAt(i) - '0');
	    newNode.next = null;
	    startNode.next = newNode;
	    startNode = startNode.next;
	    i++;
	}
	
	System.out.println(sbRes);
	return head;
    }
}


class Solution1 {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
	// can int be enough?
	int n1=0, n2=0, i=0;
	while(l1 != null) {
	    n1 = n1 + (int)Math.pow(10,i)*l1.val;
	    l1 = l1.next;
	    i++;
	}
	i=0;
	while(l2 != null) {
	    n2 = n2 + (int)Math.pow(10,i)*l2.val;
	    l2 = l2.next;
	    i++;
	}
	//	System.out.println(n1);
	//	System.out.println(n2);
	int sum = n1 + n2;
	ListNode head = new ListNode(sum % 10);
	head.next = null;
	ListNode startNode = head;
	sum /= 10;
	while (sum != 0) {
	    ListNode newNode = new ListNode(sum % 10);
	    newNode.next = null;
	    startNode.next = newNode;
	    startNode = startNode.next;
	    sum /= 10;
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
