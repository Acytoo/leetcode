class Solution:
    def trailingZeroes(self, n: int) -> int:
        rem = int(n / 5)
        return 0 if n<5 else rem + self.trailingZeroes(rem)
