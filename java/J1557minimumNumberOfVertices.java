import java.util.*;

public class J1557minimumNumberOfVertices {
  public static void main(String[] args) {
    Solution s = new Solution();

  }
}

class Solution {
  public List<Integer> findSmallestSetOfVertices(int n, List<List<Integer>> edges) {
    boolean[] in = new boolean[n];
    for (List<Integer> edge: edges) in[edge.get(1).intValue()] = true;
    List<Integer> res = new ArrayList<Integer> ();
    for (int i = 0; i < n; ++i)
      if (!in[i]) res.add(i);
    return res;
  }
}
