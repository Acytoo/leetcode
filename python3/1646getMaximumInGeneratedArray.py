class Solution:
    def getMaximumGenerated(self, n: int) -> int:
        if n == 0:
            return 0
        if n <= 2:
            return 1
        nums = [0] * (n + 1)
        nums[1] = nums[2] = 1
        res = 2
        for i in range(2, n + 1):
            if i & 1:
                nums[i] = nums[i >> 1] + nums[(i >> 1) + 1]
                res = max(res, nums[i])
            else:
                nums[i] = nums[i >> 1]
        return res


# Faster solution from leetcode
class Solution1:
    def getMaximumGenerated(self, n: int) -> int:

        if n == 0: return 0
        if n == 1: return 1

        arr = [0, 1]
        for x in range(2, n + 1):
            i, mod = divmod(x, 2)
            if mod == 0:
                arr.append(arr[i])
            else:
                arr.append(arr[i] + arr[i + 1])
        return max(arr)
