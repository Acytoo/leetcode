from typing import List


# Prefix sum
class Solution:
    def waysToMakeFair(self, nums: List[int]) -> int:
        odds, evens = [0], [0]
        n = len(nums)
        for i in range(n):
            odds.append(odds[-1] + (i & 1) * nums[i])
            evens.append(evens[-1] + (i & 1 == 0) * nums[i])
            i += 1
        res = 0
        for i in range(n):
            odd = odds[i] + evens[-1] - evens[i + 1]
            even = evens[i] + odds[-1] - odds[i + 1]
            res += odd == even
        return res


# Faster solution from leetcode
class Solution1:
    def waysToMakeFair(self, nums: List[int]) -> int:
        right = sum(nums[::2]) - sum(nums[1::2])
        res = left = 0

        for i, num in enumerate(nums):
            d = num if i & 1 else -num
            right += d
            res += right == left
            left -= d

        return res
