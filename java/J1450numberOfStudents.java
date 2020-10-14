import java.util.*;

public class J1450numberOfStudents {
  public static void main(String[] args) {
    Solution s = new Solution();

  }
}

class Solution {
  public int busyStudent(int[] startTime, int[] endTime, int queryTime) {
    int res = 0;
    for (int i = 0, n = startTime.length; i < n; ++i)
      if (startTime[i] <= queryTime && queryTime <= endTime[i])
        ++res;
    return res;
  }
}
