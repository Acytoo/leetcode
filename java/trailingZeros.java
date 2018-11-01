public class hello {
    public static void main(String[] args) {
	Solution s = new Solution();
	//	int[] a = {1,2,3,1};//res = 4
	//	int[] b = {2,7,9,3,1};//res = 12
	int a = 5;
	System.out.println(s.mySqrt(a));
    }

}

class Solution {
    public int trailingZeroes(int n) {
	int target = 0;
	for (int i=2; i < n; i++)
	    target *= i;
	target *= n;
	
    }
}
