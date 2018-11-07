public class again {
    public static void main(String[] args) {
	String a = "hello, this  is next world";
	Solution s = new Solution();
	System.out.println(s.reverseWords(a));
    }
}


class Solution {
    public String reverseWords(String s) {
	s = s.trim();
	if (s.length() == 0)
	    return s;

	StringBuilder sb = new StringBuilder();
	char[] charS = s.toCharArray();
	int pos = 0;
	boolean space = false;
	for (int i=s.length()-1; i > -1; i--) {
	    while (charS[i] == ' ') {
		i--;
		space = true;
	    }
	    if (space) {
		space = false;
		pos = sb.length();
		sb.insert(pos, ' ');
		pos++;
	    }
	    sb.insert(pos, charS[i]);
	}
	return sb.toString();
    }
}
