public class hello {
    public static void main(String[] args) {
	Solution s = new Solution();
	//	int[] a = {1,2,3,1};//res = 4
	//	int[] b = {2,7,9,3,1};//res = 12
	int a = 5;
	int b = -1;
	System.out.println(s.divide(Integer.MIN_VALUE,1));
    }

}

class Solution {
    public int divide(int dividend, int divisor) {
	// without using multiplication, division and mod operator.
	// int
	if (dividend == Integer.MIN_VALUE)
	    if (divisor == -1)
		return Integer.MAX_VALUE;
	boolean positive = true;
	positive = dividend > 0 ? true : false;
	if (positive)
	    positive = divisor > 0 ? true : false;
	else
	    positive = divisor > 0 ? false : true;
	dividend = Math.abs(dividend);
	divisor = Math.abs(divisor);
	if (dividend < divisor)
	    return 0;
	int res = 0;
	while (dividend - (divisor << 2)>= 0) {
	    dividend -= (divisor << 2);
	    res += 4;
	}
	while (dividend - (divisor << 1)>= 0) {
	    dividend -= (divisor << 1);
	    res += 2;
	}
	while (dividend >= divisor) {
	    dividend -= divisor;
	    res += 1;
	}
	return positive ? res : -1*res;
    }
}
