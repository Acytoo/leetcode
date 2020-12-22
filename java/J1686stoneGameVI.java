import java.util.*;

public class J1686stoneGameVI {
  public static void main(String[] args) {
    Solution s = new Solution();

  }
}

class Solution {
  // Greedy
  public int stoneGameVI(int[] aliceValues, int[] bobValues) {
    final int n = aliceValues.length;
    ArrayList<ArrayList<Integer>> scoreIdx = new ArrayList<ArrayList<Integer>>();
    for (int i = 0; i < n; ++i) {
      ArrayList<Integer> temp = new ArrayList<Integer>(Arrays.asList(aliceValues[i] + bobValues[i], i));
      scoreIdx.add(temp);
    }
    Collections.sort(scoreIdx, new Comparator<List<Integer>>() {
      public int compare(List<Integer> a, List<Integer> b) {
        return b.get(0).compareTo(a.get(0));
      }
    });
    int alice = 0, bob = 0;
    for (int i = 0; i < n; ++i) {
      alice += aliceValues[scoreIdx.get(i).get(1)];
      if (++i < n)
        bob += bobValues[scoreIdx.get(i).get(1)];
    }
    return alice == bob? 0: alice > bob? 1: -1;
  }
}

class Solution1 {
  // Greedy
  public int stoneGameVI(int[] aliceValues, int[] bobValues) {
    final int n = aliceValues.length;
    ArrayList<ArrayList<Integer>> scoreIdx = new ArrayList<ArrayList<Integer>>();
    for (int i = 0; i < n; ++i) {
      ArrayList<Integer> temp = new ArrayList<Integer>(Arrays.asList(aliceValues[i] + bobValues[i], i));
      scoreIdx.add(temp);
    }
    Collections.sort(scoreIdx, new Comparator<List<Integer>>() {
      public int compare(List<Integer> a, List<Integer> b) {
        return b.get(0).compareTo(a.get(0));
      }
    });
    int res = 0;
    for (int i = 0; i < n; ++i) {
      int idx = scoreIdx.get(i).get(1);
      res += ((i & 1) == 0 ? aliceValues[idx] : bobValues[idx]) * ((i & 1) == 0 ? 1 : -1);
    }
    return res < 0 ? -1 : (res > 0 ? 1 : 0);
  }
}