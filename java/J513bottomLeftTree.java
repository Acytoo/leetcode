import java.util.*;

public class J513bottomLeftTree {
  public static void main(String[] args) {
    Solution s = new Solution();

  }
}

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

// Faster solution from leetcode
class Solution {
    public int findBottomLeftValue(TreeNode root) {
        int[] max = new int[1];
        int[] res = new int[1];
        res[0] = root.val;
        dfsHelper(root, max, res, 0);
        return res[0];
    }

    private void dfsHelper(TreeNode root, int[] max, int[] res, int level) {
        if(root == null) {
            return;
        }

        if(max[0] < level) {
            res[0] = root.val;
            max[0] = level;
        }
        dfsHelper(root.left, max, res, level + 1);
        dfsHelper(root.right, max, res, level + 1);
    }
}

class Solution1 {
    public int findBottomLeftValue(TreeNode root) {
        // BFS
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        int res = root.val;
        while (!queue.isEmpty()) {
            TreeNode currentNode = queue.poll();
            if (currentNode.right != null) {
                queue.add(currentNode.right);
                res = currentNode.right.val;
            }
            if (currentNode.left != null) {
                queue.add(currentNode.left);
                res = currentNode.left.val;
            }
        }
        return res;
    }
}
