class Solution:
    def validIPAddress(self, queryIP: str) -> str:
        def isIPv4(s):
            try: return str(int(s)) == s and 0 <= int(s) <= 255
            except: return False
        def isIPv6(s):
            if len(s) > 4: return False
            try: return int(s, 16) >= 0
            except: return False

        if queryIP.count(".") == 3 and all(isIPv4(i) for i in queryIP.split(".")):
            return "IPv4"
        if queryIP.count(":") == 7 and all(isIPv6(i) for i in queryIP.split(":")):
            return "IPv6"
        return "Neither"

class Solution1:
    dic = ['1', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'a', 'b', 'c', 'd', 'e', 'f',
           'A', 'B', 'C', 'D', 'E', 'F']
    def validIPAddress(self, queryIP: str) -> str:
        if '.' in queryIP:
            strs = queryIP.split(".")
            if len(strs) != 4:
                return "Neither"
            for str_num in strs:
                if not str_num.isdigit() or int(str_num) > 255 or \
                (len(str_num) > 1 and str_num[0] == '0'):
                    return "Neither"
            return "IPv4"
        elif ':' in queryIP:
            strs = queryIP.split(":")
            if len(strs) != 8:
                return "Neither"
            for part in strs:
                if len(part) == 0 or len(part) > 4:
                    return "Neither"
                for digit in part:
                    if digit not in self.dic:
                        return "Neither"
            return "IPv6"
        else:
            return "Neither"
