public class again {
    public static void main(String[] args) {
	String a = "hello, this  is next world";
	Solution s = new Solution();
	System.out.println(s.compareVersion("1.0", "1"));
	//System.out.println(s.reverseWords(a));
	//	System.out.println("123" == "123");

    }
}

class Solution {
    public int compareVersion(String version1, String version2) {   
	String[] v1 = version1.split("\\.", 0);
	String[] v2 = version2.split("\\.", 0);
	int l1 = v1.length, l2 = v2.length, i=0, shortL = (l1 < l2) ? l1 : l2;
	while (i < shortL) {
	    if (Integer.parseInt(v1[i]) == Integer.parseInt(v2[i]))
		i++;
	    else {
		return Integer.parseInt(v1[i]) > Integer.parseInt(v2[i]) ? 1 : -1;
	    }
	}
	if (l1 == l2)
	    return 0;
	if (l1 > l2) {
	    while (i < l1 && Integer.parseInt(v1[i]) == 0)
		i++;
	    if ( i == l1)
		return 0;
	    return 1;
	}
	else  {
	    while (i < l2 && Integer.parseInt(v2[i]) == 0)
		i++;
	    if ( i == l2)
		return 0;
	    return -1;
	}
    }
}

class Solution2 {
    public int compareVersion(String version1, String version2) {
	while (version1.charAt(0) == '0') {
	    if (version1.length() == 1)
		break;
	    version1 = version1.substring(1);
	}
	while (version2.charAt(0) == '0' && version2.length() > 0) {
	    if (version2.length() == 1)
		break;
	    version2 = version2.substring(1);
	}
	if (version1 == version2)
	    return 0;
	
	int l1 = version1.length(), l2 = version2.length(), i=0, shortL = (l1 < l2) ? l1 : l2;
	while(i < shortL) {
	    if (version1.charAt(i) == version2.charAt(i))
		i++;
	    else {
		// since '.' < '0'
		return (version1.charAt(i) > version2.charAt(i)) ? 1 : -1;
	    }
	}
	if (l1 == l2)
	    return 0;
	return (l1 > l2) ? 1 : -1;
    }
}

class Solution1 {
    public int compareVersion(String version1, String version2) {
	StringBuilder v1 = new StringBuilder(version1.replace('.', '0'));
	StringBuilder v2 = new StringBuilder(version2.replace('.', '0'));
	
	int diff = v1.length() - v2.length();
	while (diff < 0) {
	    v1.append('0');
	    diff++;
	}
	while (diff > 0) {
	    v2.append('0');
	    diff--;
	}
	int vv1 = Integer.parseInt(v1.toString());
	int vv2 = Integer.parseInt(v2.toString());
	if (vv1 > vv2)
	    return 1;
	if (vv1 < vv2)
	    return -1;
	return 0;
    }
}
