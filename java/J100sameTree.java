import java.util.Stack;

public class J100sameTree {
  public static void main(String[] args) {
    Solution s = new Solution();
    Solution.TreeNode a = s.new TreeNode(1);
    Solution.TreeNode b = s.new TreeNode(2);
    Solution.TreeNode c = s.new TreeNode(3);
    Solution.TreeNode d = s.new TreeNode(4);

    Solution.TreeNode e = s.new TreeNode(1);
    Solution.TreeNode f = s.new TreeNode(2);
    Solution.TreeNode g = s.new TreeNode(3);
    Solution.TreeNode h = s.new TreeNode(4);
    Solution.TreeNode i = s.new TreeNode(5);

    a.left = b;
    a.right = c;
    c.left = d;

    e.left = f;
    e.right = g;
    g.left = h;
    h.right = i;

    System.out.println(s.isSameTree(a, e));

  }
}



class Solution {
  public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
  }

  // preorder
  public boolean isSameTree(TreeNode p, TreeNode q) {
    if (p == null) return (q == null);
    if (q == null) return false;
    Stack<TreeNode> sP = new Stack<TreeNode>();
    Stack<TreeNode> sQ = new Stack<TreeNode>();

    sP.push(p);
    sQ.push(q);

    while (!sP.isEmpty()) {
      TreeNode tP = sP.pop();
      TreeNode tQ = sQ.pop();
      if (tP.val != tQ.val) return false;

      if (tP.left != null) {
        sP.push(tP.left);
        if (tQ.left == null)
          return false;
        sQ.push(tQ.left);
      } else {  // tP.left is null
        if (tQ.left != null) return false;
      }


      if (tP.right != null) {
        sP.push(tP.right);
        if (tQ.right == null)
          return false;
        sQ.push(tQ.right);
      } else {
        if (tQ.right != null) return false;
      }

    }
    return true;
  }
}
