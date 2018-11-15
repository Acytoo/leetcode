import java.util.*;
public class sample {
    public static void main(String[] args) {
	Solution s = new Solution();
	//        String a = "/a/./b/../../c/";
	String a = "/a//b////c/d//././/..";
	System.out.println(s.simplifyPath(a));
    }
}

class Solution {
    public String simplifyPath(String path) {
	Stack <String> st = new Stack<String> ();
	String[] parts = path.split("/");
	for (String str : parts) {
	    switch (str) {
	    case "":
		break;
	    case ".":
		break;
	    case "..":
		if (!st.empty()) st.pop();
		break;
	    default :
		st.push(str);
	    }
	}
	StringBuilder sb = new StringBuilder();
	if (st.empty())
	    return "/";
	while (!st.empty()) {
	    sb.insert(0, ((String)st.pop()));
	    sb.insert(0, "/");
	}
	return sb.toString();
    }

}
