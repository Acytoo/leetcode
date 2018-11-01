public class hello {
    public static void main(String[] args) {
	Solution s = new Solution();
	ListNode a = new ListNode(1);
	ListNode b = new ListNode(2);
	a.next = b;
	b.next = null;
	ListNode res = s.rotateRight(a, 80000);
	while (res != null) {
	    System.out.print(res.val);
	    System.out.print(" ");
	    res = res.next;
	}
	System.out.println();
    }

}


// Definition for singly-linked list.
class ListNode {
     int val;
     ListNode next;
     ListNode(int x) { val = x; }
}
// record the tail, while loop the k, while the length is greater than the length of list, go back and again, o(n) in time, and no additional space.
class Solution {
    public ListNode rotateRight(ListNode head, int k) {
	if (head == null || k == 0)
	    return head;
	ListNode tail, newHead, slow;
	int temp = 0;
	tail = head;
	newHead = head;
	while (k > 0) {
	    k--;
	    temp++;
	    if (newHead.next == null) {
		tail = newHead;
		newHead = head;
		k = k % temp;
		continue;
	    }
	    newHead = newHead.next;
	}
	if (newHead == head)
	    return head;
	slow = head;
	while (newHead.next != null) {
	    slow = slow.next;
	    newHead = newHead.next;
	}
	ListNode res = slow.next;
	slow.next = null;
	newHead.next = head;
	return res;
    }
}
/*8ms version from leetcode*/

class Solution_l {
    public ListNode rotateRight(ListNode head, int k) {
    	if(head == null){
    		return null ; 
    	}
        int n = 0 ; 
        ListNode p = head ;
        while(p != null){
        	n++ ; 
        	p = p.next; 
        }
        k = k%n; 
        p = head; 
        while(p != null && k-- > 0){
        	p = p.next ; 
        }
        ListNode q = head ; 
        while(p.next != null){
        	p = p.next ; 
        	q = q.next ; 
        }
        p.next = head ; 
        ListNode result = q.next ; 
        q.next = null ; 
        return result ; 
    }
}
