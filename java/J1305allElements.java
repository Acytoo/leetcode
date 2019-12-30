import java.util.*;

public class J1305allElements {
  public static void main(String[] args) {
    Solution s = new Solution();

  }
}

class Solution {
  public List<Integer>  getAllElements(TreeNode a, TreeNode b) {
    res_ = new ArrayList<>();
    dfs(a);
    dfs(b);
    Collections.sort(res_);
    return res_;

  }

  private void dfs(TreeNode a) {
    if (a == null)
      return;
    res_.add(a.val);
    dfs(a.left);
    dfs(a.right);
  }

  private ArrayList<Integer> res_;

}
