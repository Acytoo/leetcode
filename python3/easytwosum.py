class Solution:

    def twoSum_ugly(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        i = 0
        while i < len(nums):
            j = i + 1
            while j < len(nums):
                if target == nums[i] + nums[j]:
                    return [i, j]
                else:
                    j += 1
            i += 1
        return None

    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        num2idx = {}
        for idx, val in enumerate(nums):
            if target - val in num2idx:
                return num2idx[target - val], idx
            num2idx[val] = idx


if __name__ == '__main__':
    s = Solution()
    print(s.twoSum([2, 7, 11, 15], 13))
