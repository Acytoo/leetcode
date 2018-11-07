public class sample {
    public static void main(String[] args) {
	Solution s = new Solution();
	int[] a = {-2,1,-3,4,-1,2,1,-5,4};
	System.out.println(s.maxSubArray(a));

    }
}

class Solution {
    public int maxSubArray(int[] nums) {
        int i = 1, maxCurrent = nums[0], tempMax = maxCurrent;
	if (nums.length == 1)
	    return maxCurrent;
	for (; i < nums.length; i++) {
	    tempMax = Math.max(tempMax+nums[i], nums[i]);
	    maxCurrent = Math.max(maxCurrent, tempMax);
	}
	return maxCurrent;
    }
}
