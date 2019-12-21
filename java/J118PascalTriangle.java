import java.util.*;

public class J118PascalTriangle {
  public static void main(String[] args) {
    int a = 3;
    Solution s = new Solution();
    s.generate(a);
  }
}


class Solution {
  public List<List<Integer>> generate(int numRows) {
    List<List<Integer>> res = new ArrayList<>();

    if (numRows == 0) return res;

    List<Integer> firstRow = new ArrayList<>();
    firstRow.add(1);
    res.add(firstRow);

    for (int i=1; i<numRows; ++i) {
      List<Integer> preRow = res.get(i-1);
      List<Integer> row = new ArrayList<>();

      row.add(1);  // add fitst element;

      for (int j=1; i<1; ++j) {
        row.add(preRow.get(j-1) + preRow.get(j));
      }

      row.add(1);  // add last element;
      res.add(row);

    }
    return res;
  }
}
