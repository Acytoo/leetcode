import java.util.*;

public class J49groupAnagrams {
  public static void main(String[] args) {
    Solution s = new Solution();

  }
}


// faster solution from leetcode

class Solution {
  public List<List<String>> groupAnagrams(String[] strs) {
    List<List<String>> res = new ArrayList<>();
    Map<String, List<String>> map = new HashMap<>();
    for(int i=0;i<strs.length;i++){
      String tmp = getString(strs[i]);
      if(map.containsKey(tmp)){
        map.get(tmp).add(strs[i]);
      }else {
        List<String> tmpAns = new ArrayList<>();
        tmpAns.add(strs[i]);
        map.put(tmp,tmpAns);
        res.add(tmpAns);
      }
    }
    return res;
  }

  private String getString(String str){
    char[] fre = new char[26];
    for(int i=0;i<str.length();i++){
      fre[str.charAt(i) - 'a']++;
    }
    return new String(fre);
  }
}

class Solution1 {
  public List<List<String>> groupAnagrams(String[] strs) {
    HashMap<String, ArrayList<String>> map = new HashMap<>();
    for (String s: strs) {
      int[] letters = new int[26];
      for (int i=0,stop=s.length(); i<stop; ++i)
        ++letters[s.charAt(i)-'a'];
      String key = Arrays.toString(letters);
      ArrayList<String> tmp = map.getOrDefault(key, new ArrayList<String>());
      tmp.add(s);
      map.put(key, tmp);
    }
    return new ArrayList<>(map.values());
  }
}
