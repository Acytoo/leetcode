import java.util.*;

public class J1313decompress {
  public static void main(String[] args) {
    Solution s = new Solution();

  }
}


class Solution {
  public int[] decompressRLElist(int[] nums) {
    int count = 0;
    for(int i = 0; i < nums.length; i = i + 2){
      count += nums[i];
    }
    int[] ans = new int[count];
    int st = 0;
    for(int j = 1; j < nums.length; j = j + 2){
      Arrays.fill(ans, st, st + nums[j-1], nums[j]);
      st += nums[j - 1];
    }
    return ans;
  }
}


class Solution1 {
  public int[] decompressRLElist(int[] nums) {
    ArrayList<Integer> list = new ArrayList<>();
    for (int i=1, stop=nums.length; i<stop; i+=2) {
      for (int j=nums[i-1]; j>0; --j)
        list.add(nums[i]);
    }
    int[] res = list.stream().mapToInt(Integer::intValue).toArray();
    return res;
  }
}
