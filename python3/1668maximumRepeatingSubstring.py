class Solution:
    def maxRepeating(self, sequence: str, word: str) -> int:
        if len(sequence) < len(word):
            return 0
        if len(sequence) == len(word):
            return sequence == word
        res = 0
        s = word
        while True:
            if (sequence.find(s) == -1):
                return res
            s += word
            res += 1
