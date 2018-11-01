public class hello {
    public static void main(String[] args) {
	Solution s = new Solution();
	int[] a = {1,2,3,1};//res = 4
	int[] b = {2,7,9,3,1};//res = 12
	
	System.out.println(s.rob(b));
    }

}




class Solution {
    public int rob(int[] nums) {
	if (nums.length < 1)
	    return 0;
	int p1=0, p2=0, temp=0;
	for (int p : nums) {
	    temp = p2;
	    p2 = Math.max(p1+p, p2);
	    p1 = temp;
	}
	return p2;
    }
}
    
// class Solution {
//     public int rob(int[] nums) {
// 	return rob(nums, nums.length - 1);
//     }
//     private int rob(int[] nums, int i) {
// 	if (i < 0) {
// 	    return 0;
// 	}
// 	return Math.max(rob(nums, i - 2) + nums[i], rob(nums, i - 1));
//     }
// }

