import java.util.*;

public class J1019nextGreaterInLinked {
  public static void main(String[] args) {
    Solution s = new Solution();

  }
}


class Solution {
  public int[] nextLargerNodes(ListNode head) {
    List<Integer> numsList = new ArrayList<>();
    while (head != null) {
      numsList.add(head.val);
      head = head.next;
    }

    int[] res = new int[numsList.size()];
    Stack<Integer> stack = new Stack<>();
    for (int i = 0; i < numsList.size(); ++i) {
      while (!stack.isEmpty() && numsList.get(stack.peek()) < numsList.get(i))
        res[stack.pop()] = numsList.get(i);
      stack.push(i);
    }
    return res;
  }
}
