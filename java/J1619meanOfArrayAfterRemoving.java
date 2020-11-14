import java.util.*;

public class J1619meanOfArrayAfterRemoving {
  public static void main(String[] args) {
    Solution s = new Solution();

  }
}

class Solution {
  public double trimMean(int[] arr) {
    int sum = 0, n = arr.length, r = n / 20;
    Arrays.sort(arr);
    for (int i = r, stop = n - r; i < stop; ++i) sum += arr[i];
    return (double)sum / (n - (r << 1));
  }
}

class Solution1 {
  public double trimMean(int[] arr) {
    double sum = .0;
    int n = arr.length, r = (int)(n * 0.05);
    Arrays.sort(arr);
    for (int i = r, stop = n - r; i < stop; ++i) sum += arr[i];
    return sum / (n - (r << 1));
  }
}
