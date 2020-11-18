class Solution:
    def minDeletions(self, s: str) -> int:
        chars = [0] * (ord('z') + 1)
        for c in s:
            chars[ord(c)] += 1
        freq = set()
        res = 0
        for c in range(ord('a'), ord('z') + 1):
            while chars[c] in freq and chars[c] > 0:
                res += 1
                chars[c] -= 1
            if chars[c] > 0:
                freq.add(chars[c])
        return res

# More pythonic and faster solution form leetcode
from collections import Counter
class Solution1:
    def minDeletions(self, s: str) -> int:
        c = Counter(s)
        freq_set = set()
        lis = sorted(c.values(), reverse=True)
        res = 0
        for i in lis:
            while i in freq_set:
                i -= 1
                res += 1
            if i:
                freq_set.add(i)
        return res

if __name__ == '__main__':
    s = Solution()
    print(s.minDeletions("abab"))
