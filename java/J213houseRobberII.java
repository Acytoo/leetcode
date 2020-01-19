import java.util.*;

public class J213houseRobberII {
    public static void main(String[] args) {
        Solution s = new Solution();

    }
}

class Solution {
    public int rob(int[] nums) {
        int n = nums.length;
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];
        return Math.max(rob(nums, 0, n-2), rob(nums, 1, n-1));
    }
    private int rob(int[] n, int l, int r) {
        int cur = 0;
        int pre = 0;
        int ppre = 0;
        for (int i=l; i<=r; ++i) {
            cur = Math.max(ppre+n[i], pre);
            ppre = pre;
            pre = cur;
        }
        return cur;
    }
}
