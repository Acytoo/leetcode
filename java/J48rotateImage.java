import java.util.*;

class Solution {
  public void rotate(int[][] matrix) {
    if (matrix == null) return;
    int n = matrix.length, top = 0, bottom = n-1, left = 0, right = bottom;
    while (n>1) {
      for (int i=0, stop=n-1; i<stop; ++i) {
        int tmp = matrix[top][left+i];
        matrix[top][left+i] = matrix[bottom-i][left];
        matrix[bottom-i][left] = matrix[bottom][right-i];
        matrix[bottom][right-i] = matrix[top+i][right];
        matrix[top+i][right] = tmp;
      }
      ++top;
      --bottom;
      ++left;
      --right;
      n-=2;
    }
  }
}

public class J48rotateImage {
  public static void main(String[] args) {
    System.out.println("Asdad");
  }
}
