class Solution:
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        lenOri = len(nums)
        nums = set(nums)
        return len(nums) != lenOri
