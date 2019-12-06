import java.util.Stack;


public class J173bstIt {
    public static void main(String[] args) {

    }
}



class BSTIterator {

    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) { val = x; }
    }
    TreeNode root;
    Stack<TreeNode> s;

    public BSTIterator(TreeNode root) {
        s = new Stack<TreeNode>();
        this.root = root;
    }


    /** @return the next smallest number */
    public int next() {
        while (root != null) {
            s.push(root);
            root = root.left;
        }
        root = s.pop();
        int v = root.val;
        root = root.right;
        return v;
    }


    /** @return whether we have a next smallest number */
    public boolean hasNext() {
        return !s.empty() || root != null;
    }
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator obj = new BSTIterator(root);
 * int param_1 = obj.next();
 * boolean param_2 = obj.hasNext();
 */
