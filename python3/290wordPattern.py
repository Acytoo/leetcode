class Solution:
    def wordPattern(self, pattern: str, str: str) -> bool:
        words = str.split()
        if len(pattern) != len(words):
            return False
        i = 0
        dict_pattern = {}
        for letter, word in zip(pattern, words):
            if letter in dict_pattern:
                if dict_pattern[letter] != word:
                    return False;
            elif word in dict_pattern.values():
                return False
            else:
                dict_pattern[letter] = word
        return True

a = "abba"
b = "dog cat cat dog"
a = "abba"
b = "dog dog dog dog"

s = Solution()
print(s.wordPattern(a, b))
