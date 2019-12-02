import java.util.*;

public class J648replaceWords {
    public static void main(String[] args) {
        Solution s = new Solution();
        List<String> dict = Arrays.asList("cat", "set", "map");
        String a = "catwer cat23 mat45";
        String res = s.replaceWords(dict, a);
        System.out.println(res);
    }
}
class Solution {
    public String replaceWords(List<String> dict, String sentence) {
        Set<String> set = new HashSet<String>(dict);
        StringBuilder sb = new StringBuilder();
        String[] words = sentence.split(" ");
        for (int i=0; i<words.length; ++i) {
            for (int j=1; j<=words[i].length(); ++j) { // Sort first?
                String root = words[i].substring(0, j);
                if (set.contains(root)) {
                    words[i] = root;
                }
            }
            sb.append(words[i] + " ");
        }
        return sb.substring(0, sb.length()-1);
    }
}
