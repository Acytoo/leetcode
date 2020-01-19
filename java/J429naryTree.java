import java.util.*;

public class J429naryTree {
    public static void main(String[] args) {
        Solution s = new Solution();

    }
}

/*
// Definition for a Node.
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
*/

// BFS
class Solution1 {
    public List<List<Integer>> levelOrder(Node root) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        if (root == null)
            return res;

        Queue<Node> queue = new LinkedList<>();
        queue.add(root);
        while (!queue.isEmpty()) {
            List<Integer> curLevel = new ArrayList<>();
            for (int i=0, stop=queue.size(); i<stop; ++i) {
                Node cur = queue.poll();
                curLevel.add(cur.val);
                for (Node child: cur.children)
                    queue.add(child);
            }
            res.add(curLevel);
        }
        return res;
    }
}
