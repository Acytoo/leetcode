public class J2twoSum {
  public static void main(String[] args) {
    Solution s = new Solution();
    int[] nums = new int[] (1,2,3,4,5);
    int tar = 5;
    int[] res = s.twoSum(nums, tar);
    System.out.println(res[0], res[1]);
  }
}





class Solution {
  public int[] twoSum(int[] nums, int target) {
    int[] res = new int[2];
    if (nums.length <= 1) return res;
    HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
    for (int i=0; i<nums.length; ++i) {
      int num = num[i];
      int val = target - num;
      if (map.containsKey(val)) {
        res[0] = i;
        res[1] = map.get(val);
        return res;
      } else map.put(num, i);
    }
    return res;
  }
}
