import java.util.*;

public class J1002findCommonChar {
  public static void main(String[] args) {
    Solution s = new Solution();

  }
}
// Faster solution from leetcode
class Solution {
    public List<String> commonChars(String[] A) {
        int[] ans = new int[26];
        List<String> ans_list = new ArrayList<>();
        if (A == null || A.length == 0) return ans_list;
        // use first item as template
        for (char c : A[0].toCharArray()) {
            ans[c - 'a']++;
        }

        // vrify every string in str_array
        for (int i=1; i<A.length; i++) {
            verify(ans, A[i]);
        }

        // output ans
        for(int i=0; i<26; i++){
            while(ans[i] != 0){
                ans_list.add(Character.toString((char) ('a' + i)));
                ans[i]--;
            }
        }
        return ans_list;

    }

    private void verify(int[] ans, String cur) {
        int[] arr_cur = new int[26];
        for (char c : cur.toCharArray()) {
            arr_cur[c - 'a']++;
        }

        //verify the letter
        for(int i=0; i<26; i++){
            ans[i] = Math.min(ans[i], arr_cur[i]);
        }

    }
}

class Solution1 {
  public List<String> commonChars(String[] A) {
    int n = A.length;
    int[][] chars =  new int [n][26];
    for (int i=0; i<n; ++i)
      for (int j=0, stop=A[i].length(); j<stop; ++j) {
        ++chars[i][A[i].charAt(j)-'a'];
      }
    List<String> res = new ArrayList<>();
    for (int i=0; i<26; ++i) {
      int max = Integer.MAX_VALUE;
      for (int j=0; j<n; ++j)
        max = Math.min(max, chars[j][i]);
      while (0 < max--)
        res.add(Character.toString((char)('a'+i)));
    }
    return res;
  }
}
