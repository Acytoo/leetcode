import java.util.*;

public class J1234Template {
  public static void main(String[] args) {
    Solution s = new Solution();

  }
}
// Fast solution from leetcode
class Solution {
  List<Integer> res = new ArrayList<>();
  public List<Integer> postorder(Node root) {
    if (root == null) return res;

    if (root.children != null) {
      int size = root.children.size();

      for (int i = 0; i < size; i++) {
        postorder(root.children.get(i));
      }

      res.add(root.val);

    } else {
      return res;
    }
    return res;

  }
}

class Solution1 {

  class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
      val = _val;
    }

    public Node(int _val, List<Node> _children) {
      val = _val;
      children = _children;
    }
  };


  public List<Integer> postorder(Node root) {
    // #1 convert Nodes to tree
    // #2 Using stack
    LinkedList<Node> stack = new LinkedList<>();
    LinkedList<Integer> res = new LinkedList<>();

    if (root == null) return res;

    stack.add(root);

    while (!stack.isEmpty()) {
      Node node = stack.pollLast();
      res.addFirst(node.val);
      for (Node child: node.children) {
        stack.add(child);
      }
    }
    return res;
  }
}
