import java.util.*;

public class J1306jumpGameIII {
  public static void main(String[] args) {
    Solution s = new Solution();

  }
}


class Solution {
  public boolean canReach(int[] arr, int start) {
    // bfs
    int n = arr.length;
    Queue<Integer> q = new LinkedList<>();
    boolean[] visited = new boolean[n];

    visited[start] = true;
    q.add(start);

    while (!q.isEmpty()) {
      int cur = q.poll();  // return null when queue is empty
      int step = arr[cur];

      if (step == 0)
        return true;

      int nextIdx = cur-step;
      if (nextIdx>=0 && !visited[nextIdx]) {
        visited[nextIdx] = true;
        q.add(nextIdx);
      }
      nextIdx = cur+step;
      if (nextIdx<n && !visited[nextIdx])  {
        visited[nextIdx] = true;
        q.add(nextIdx);
      }
    }
    return false;
  }

}
