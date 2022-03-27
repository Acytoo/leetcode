class Solution:
    def findDifference(self, nums1: List[int], nums2: List[int]) -> List[List[int]]:
        nums = set(nums1 + nums2)
        return [nums - set(nums2), nums - set(nums1)]
