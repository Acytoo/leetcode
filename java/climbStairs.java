public class sample {
    public static void main(String[] args) {
	Solution s = new Solution();
	//	int[] a = {-2,1,-3,4,-1,2,1,-5,4};
	System.out.println(s.climbStairs(5));

    }
}

class Solution {
    public int climbStairs(int n) {
	int p1 = 1, p2 = 2, p3 = 3, res;
	if (n < 3)
	    return n;
	for (int i=2; i < n; i++) {
	    p3  = p1 + p2;
	    p1 = p2;
	    p2 = p3;
	}
	return p3;
    }
}
