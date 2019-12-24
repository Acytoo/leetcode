import java.util.*;

public class J257BiTreePath {
  public static void main(String[] args) {
    Solution s = new Solution();

  }
}



class Solution {

  public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
  }

  public List<String> binaryTreePaths(TreeNode root) {
    List<String> res = new ArrayList<>();
    if (root == null)
      return res;
    if (root.left == null && root.right == null) {
      res.add(String.valueOf(root.val));
    } else {
      for (String s : binaryTreePaths(root.left)) {
        res.add(String.valueOf(root.val) + "->" + s);
      }
      for (String s : binaryTreePaths(root.right)) {
        res.add(String.valueOf(root.val) + "->" + s);
      }
    }

    return res;
  }
}
