import java.util.*;

public class J101symmetricTree {
  public static void main(String[] args) {
    Solution s = new Solution();

  }
}

class Solution {
    // recursively
    public boolean isSymmetric1(TreeNode root) {
        if (root == null)
            return true;
        return dfs(root.left, root.right);
    }
    private boolean dfs(TreeNode a, TreeNode b) {
        if (a==null || b==null)
            return a==null && b==null;
        return a.val == b.val && dfs(a.left, b.right) && dfs(a.right, b.left);
    }

    // iteratively
    public boolean isSymmetric(TreeNode root) {
        if (root == null)
            return true;

        Stack<TreeNode> leftStack = new Stack<>();
        Stack<TreeNode> rightStack = new Stack<>();
        TreeNode a = root.left, b = root.right;
        while (a!=null || b!=null ||
               !leftStack.isEmpty() || !rightStack.isEmpty()) {
            while (a!=null && b!=null) {
                leftStack.push(a);
                a = a.left;
                rightStack.push(b);
                b = b.right;
            }

            if (a!=null || b!=null)
                return false;

            a = leftStack.pop();
            b = rightStack.pop();
            if (a.val != b.val)
                return false;

            a = a.right;
            b = b.left;

        }
        return true;
    }
}
