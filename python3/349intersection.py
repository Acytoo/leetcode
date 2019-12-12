from typing import List

class Solution:
    def intersection1(self, nums1: List[int], nums2: List[int]) -> List[int]: # 56ms, 12.8mb
        nums1 = set(list(nums1))
        res = [i for i in nums1 if i in nums2]
        return res
    def intersection2(self, nums1, nums2): # 40ms, 12.8mb
        return list(set(nums1) & set(nums2))
    def intersection(self, nums1, nums2): # 36ms, 12.9mb
        return list(set(nums1).intersection(nums2))


if __name__ == '__main__':
    s = Solution()
    a = [1, 2]
    b = [3, 4, 2, 2, 2]
    res = s.intersection(a, b)
    print(res)
