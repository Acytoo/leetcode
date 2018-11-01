public class hello {
    public static void main(String[] args) {
	Solution s = new Solution();
	String a = "  -913 32";

	System.out.println(s.myAtoi(a));
    }

}

class Solution {
    public int onlyNum(String str, boolean positive) {
	int result;
	try {
	    result = Integer.parseInt(str);
	} catch (java.lang.Exception e) {
	    return positive ? Integer.MAX_VALUE : Integer.MIN_VALUE;
	}
	return positive ? result : -1*result;
    }
    public int myAtoi(String str) {
	str = str.trim();
	int strTail = str.length();
	if (strTail == 0)
	    return 0;
	char[] cstr = str.toCharArray();
	boolean positive;
	String strNum;
	if (cstr[0] == '+') {
	    int i=1;
	    // '0':48 '9':57
	    while (i < strTail && 47 < cstr[i] && cstr[i] < 58)
		i++;
	    if (i > 1)
		return onlyNum(String.valueOf(cstr).substring(1,i), true);
	    return 0;
	}
	if (cstr[0] == '-') {
	    int i=1;
	    while (i < strTail && 47 < cstr[i] && cstr[i] < 58)
		i++;
	    if (i > 1)
		return onlyNum(String.valueOf(cstr).substring(1,i), false);
	    return 0;
	}
	int i=0;
	while (i < strTail && 47 < cstr[i] && cstr[i] < 58)
	    i++;
	if (i > 0)
	    return onlyNum(String.valueOf(cstr).substring(0,i),true);
	return 0;
    }
}
