import java.util.*;

public class J1110deleteNode {
  public static void main(String[] args) {
    Solution s = new Solution();

  }
}

class Solution {
  public List<TreeNode> delNodes(TreeNode root, int[] to_delete) {
    a_ = to_delete;
    n_ = a_.length-1;
    res_ = new ArrayList<>();
    delCur(root, true);
    return res_;
  }

  private TreeNode delCur(TreeNode cur, boolean isRoot) {
    if (cur == null)
      return null;
    boolean deleted = toDelete(cur.val);
    if (isRoot && !deleted)
      res_.add(cur);
    cur.left = delCur(cur.left, deleted);
    cur.right = delCur(cur.right, deleted);
    return deleted? null: cur;
  }

  private boolean toDelete(int a) {
    for (int i=0; i<=n_; ++i) {
      if (a_[i] == a) {
        int tmp = a_[i];
        a_[i] = a_[n_];
        a_[n_] = tmp;
        --n_;
        return true;
      }
    }
    return false;
  }

  private List<TreeNode> res_;
  private int n_;
  private int[] a_;
}

class Solution_wrong {
  public List<TreeNode> delNodes(TreeNode root, int[] to_delete) {
    a_ = to_delete;
    n_ = a_.length-1;
    TreeNode pre = new TreeNode(-1);
    pre.left = root;
    res_ = new ArrayList<>();
    Stack<TreeNode> nodes = new Stack<TreeNode>();

    nodes.add(pre);
    if (inArray(root.val))
      delCur(root);
    else
      res_.add(root);

    while (n_ >= 0 && !nodes.isEmpty()) {
      TreeNode cur = nodes.pop();

      if (cur.left != null) {
        if (inArray(cur.left.val))
          delCur(cur.left);
        nodes.push(cur.left);
      }
      if (cur.right != null) {
        if (inArray(cur.right.val))
          delCur(cur.right);
        nodes.push(cur.right);
      }

    }

    return res_;
  }

  private boolean inArray(int a) {
    for (int i=0; i<=n_; ++i) {
      if (a_[i] == a) {
        int tmp = a_[i];
        a_[i] = a_[n_];
        a_[n_] = tmp;
        --n_;
        return true;
      }
    }
    return false;
  }

  private void delCur(TreeNode cur) {
    if (cur.left != null) {
      if (!inArray(cur.left.val)) {
        res_.add(cur.left);
        cur.left = null;
      } else {
        delCur(cur.left);
      }
    }

    if (cur.right != null) {
      if (!inArray(cur.right.val)) {
        res_.add(cur.right);
        cur.right = null;
      } else {
        delCur(cur.right);
      }
    }
  }

  private List<TreeNode> res_;
  private int n_;
  private int[] a_;
}
