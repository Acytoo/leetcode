import java.util.*;

public class J503nextGreaterEleII {
  public static void main(String[] args) {
    Solution s = new Solution();

  }
}

class Solution {
    public int[] nextGreaterElements(int[] nums) {
        int length = nums.length;
        int[] res = new int[length];
        int twoLength = 2 * length;
        int[] index = new int[twoLength];
        for (int i = length; i < twoLength; i++) {
            index[i] = i - length;
        }
        int current = length;
        for (int i = length - 1; i >= 0; i--) {
            while (current < twoLength && nums[index[current]] <= nums[i]) {
                current++;
            }
            if (current == twoLength) {
                res[i] = -1;
            } else {
                res[i] = nums[index[current]];
            }
            current--;
            index[current] = i;
        }
        return res;
    }
}

// Simple but slow
class Solution1 {
    public int[] nextGreaterElements(int[] nums) {
        int n = nums.length;
        int[] res = new int[n];
        for (int i=0; i<n; ++i) {
            int j=1;
            while (j<=n) {
                if (nums[i] < nums[(i+j)%n]) {
                    res[i] = nums[(i+j)%n];
                    break;
                }
                ++j;
            }
            if (j > n)
                res[i] = -1;
        }
        return res;
    }
}
