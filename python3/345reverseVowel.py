class Solution:
    def reverseVowels(self, s: str) -> str:
        vow = 'aeiou'
        i, j = 0, len(s)-1
        s = list(s)
        while i<j:
            if s[i] not in vow:
                i+=1
                continue
            if s[j] not in vow:
                j-=1
                continue
            elif s[i] in vow and s[j] in vow:
                tmp = s[i]
                s[i] = s[j]
                s[j] = tmp
                i+=1
                j-=1
        return ''.join(s)
