public class sample {
    public static void main(String[] args) {
	Solution s = new Solution();
        String a = "/a/./b/../../c/";
	System.out.println(s.simplifyPath(a));
    }
}

class Solution {
    public String simplifyPath(String path) {
	String[] parts = path.split("/");
	StringBuilder res = new StringBuilder();
	int[] lengths = new int[parts.length+1];
	lengths[0] = 0;
	int i=1;
	for (String str : parts) {
	    if ( str.equals(""))
		continue;
	    if (str.equals("."))
	     	continue;
	    if (str.equals("..")) {
		//		 System.out.println("asdadsasdadsads");
		if (i != 1)
		    try {
			//			System.out.println(i);
			//			System.out.println(res.toString());
			//			for (int j=0; j < lengths.length-1; j++)
			//			    System.out.printf("%d ", lengths[j]);
			res = res.delete(lengths[i-1]-1, res.length());
		    } catch (java.lang.StringIndexOutOfBoundsException e) {
			res = new StringBuilder();
		    }
		continue;
	    }
	    res.append("/");
	    //	    System.out.println(str);
	    //	    System.out.println(i);
	    res.append(str);
	     
	    lengths[i] = res.length()-1;
	    i++;
	     
	    
	}
	return res.toString();
    }
}
