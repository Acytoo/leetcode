import java.util.*;

public class J506relativeRank {
  public static void main(String[] args) {
    Solution s = new Solution();
    int[] nums = {1,2,3,4,5};
    String[] res = s.findRelativeRanks(nums);
    for (String str: res) {
        System.out.printf("%s ", str);
    }
    System.out.println();
  }
}

// Faster solution from leetcode
class Solution {
    public String[] findRelativeRanks(int[] nums) {
        int maxValue = 0;
        for (int i = 0; i < nums.length; i ++) {
            if (nums[i] > maxValue) {
                maxValue = nums[i];
            }
        }

        int[] bucket = new int[maxValue+1];

        for (int i = 0; i < nums.length; i ++) {
            bucket[nums[i]] = i+1;
        }

        int place = 1;
        String[] answer = new String[nums.length];
        for (int i = bucket.length-1; i >= 0; i --) {
            if (bucket[i] != 0) {
                if (place <= 3) {
                    if (place == 3) {
                        answer[bucket[i]-1] = "Bronze Medal";
                    }
                    else if (place == 2) {
                        answer[bucket[i]-1] = "Silver Medal";
                    }
                    else {
                        answer[bucket[i]-1] = "Gold Medal";
                    }
                }
                else {
                    answer[bucket[i]-1] = place+"";
                }
                place++;
            }
        }

        return answer;
    }
}

// Slow but easy ot understand
class Solution1 {
    public String[] findRelativeRanks(int[] nums) {
        Map<Integer, Integer> rank = new TreeMap<>();
        int n = nums.length;
        for (int i=0; i<n; ++i)
            rank.put(nums[i], i);
        String[] res = new String[n];
        Collection indexes = rank.values();
        Iterator it = indexes.iterator();
        while (it.hasNext()) {
            if (3 < n)
                res[(int)it.next()] = n + "";
            else if (n == 3)
                res[(int)it.next()] = "Bronze Medal";
            else if (n == 2)
                res[(int)it.next()] = "Silver Medal";
            else
                res[(int)it.next()] = "Gold Medal";
            --n;
        }
        return res;
    }
}
