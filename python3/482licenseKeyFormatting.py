class Solution:
    def licenseKeyFormatting(self, s: str, k: int) -> str:
        s = s.replace('-', '').upper()
        n = len(s)
        if n == 0:
            return ""
        rem = n % k
        res = s[:rem]
        rest = s[rem:]
        i, n = 0, len(rest)
        while i < n:
            if i % k == 0:
                res += '-'
            res += rest[i]
            i += 1
        if res[0] == '-':
            res = res[1:]
        return res
