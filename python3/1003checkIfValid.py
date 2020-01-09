class Solution:
    def isValid(self, s: str) -> bool:
        ss = ""
        while s != ss:
            s, ss = s.replace("abc", ""), s
        return s == ""
