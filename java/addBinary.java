public class hello {
    public static void main(String[] args) {
	Solution s = new Solution();
	String a = "1011";
	String b = "1010";
	System.out.println(s.addBinary(a,b));
    }

}

class Solution {
    public String addBinary(String astr, String bstr) {
	StringBuilder res = new StringBuilder();
	char[] a = astr.toCharArray();
	char[] b = bstr.toCharArray();
	int la = a.length-1, lb = b.length-1, carry = 0, temp=0;
	while (la >= 0 || lb >= 0 || carry > 0) {
	    char tempA, tempB, lefted;
	    tempA = la < 0 ? '0' : a[la];
	    tempB = lb < 0 ? '0' : b[lb];
	    temp = tempA ^ tempB;
	    res.append(temp ^ carry);
	    if (temp == 0)
		carry = tempA == '1' ? 1 : 0;
	    la--;
	    lb--;
	}

	return res.reverse().toString();
    }
}
