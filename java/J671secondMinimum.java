import java.util.*;

public class J671secondMinimum {
  public static void main(String[] args) {
    Solution s = new Solution();

  }
}

class Solution {
    public int findSecondMinimumValue(TreeNode root) {
        if (root.right == null) return -1;
        // 一定在叶子节点中，先找出所有的叶子节点，然后选择第二小
        Stack<TreeNode> stack = new Stack<>();
        ArrayList<Integer> leaf = new ArrayList<>();
        stack.push(root);
        while (!stack.isEmpty()) {
            TreeNode cur = stack.pop();
            if (cur.left == null) {
                leaf.add(cur.val);
            } else {
                stack.push(cur.right);
                stack.push(cur.left);
            }
        }
        int i=0, fir=Integer.MAX_VALUE, sec=Integer.MAX_VALUE, n=leaf.size();
        while (i != n) {
            int tmp = leaf.get(i);
            if (tmp < sec) {
                if (tmp < fir) {
                    sec = fir;
                    fir = tmp;
                } else if (tmp != fir) {
                    sec =  tmp;
                }
            }
            ++i;
        }

        if (sec != Integer.MAX_VALUE) return sec;
        if (leaf.get(n-1) == Integer.MAX_VALUE) return sec;
        return -1;
    }
}
