public class hello {
    public static void main(String[] args) {
	Solution s = new Solution();
	int a = 951;

	System.out.println(s.reverse(a));
    }

}

class Solution {
    public int reverse(int x) {
	int absx = Math.abs(x);
	String strX = String.valueOf(absx);
	String res = new StringBuilder(strX).reverse().toString();
	int temp, resInt;
	try {
	    temp = Integer.parseInt(res);
	    resInt = x > 0 ? temp : -1*temp;
	}
	catch (java.lang. Exception e){
	    resInt = 0;
	}
	return resInt;
    }
}
