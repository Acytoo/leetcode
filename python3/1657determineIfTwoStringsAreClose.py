import collections


# Pythonic solution
class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        if (len(word2) != len(word1)):
            return False
        c1, c2 = collections.Counter(word1), collections.Counter(word2)
        return c1.keys() == c2.keys() and sorted(c1.values()) == sorted(c2.values())


class Solution1:
    def closeStrings(self, word1: str, word2: str) -> bool:
        if len(word1) != len(word2):
            return False
        chars1 = [0] * (ord('z') + 1)
        for c in word1:
            chars1[ord(c)] += 1
        chars2 = [0] * (len(chars1))
        for c in word2:
            chars2[ord(c)] += 1
        for i in range(ord('a'), ord('z')):
            if (chars1[i] + chars2[i]) != 0 and (chars1[i] * chars2[i]) == 0:
                return False
        chars1.sort()
        chars2.sort()
        return chars1 == chars2
