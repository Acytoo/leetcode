import java.util.*;

public class J448findDisappear {
  public static void main(String[] args) {
    Solution s = new Solution();

  }
}

class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        int n = nums.length+1;
        int[] dict = new int[n];
        for (int i: nums)
            ++dict[i];
        ArrayList<Integer> res = new ArrayList<>();
        for (int i=1; i<n; ++i)
            if (dict[i] == 0)
                res.add(i);
        return res;
    }
}
