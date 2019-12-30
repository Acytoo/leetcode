import java.util.*;

public class J1302deepestLeavesSum {
  public static void main(String[] args) {
    Solution s = new Solution();

  }
}

class Solution {
  public int deepestLeavesSum(TreeNode root) {
    if (root.left==null && root.right==null)
      return root.val;
    // 利用层次遍历
    Queue<TreeNode> q = new LinkedList<>();
    q.offer(root);
    int res = 0;

    while (!q.isEmpty()) {
      int size = q.size();
      res = 0;
      while (size-- > 0) {
        TreeNode top = q.poll();
        res += top.val;
        if (top.left != null) q.offer(top.left);
        if (top.right != null) q.offer(top.right);
      }
    }
    return res;
  }
}
