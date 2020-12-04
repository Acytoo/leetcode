class Solution:
    def kthFactor(self, n: int, k: int) -> int:
        nn = n + 1
        for i in range(1, nn):
            if n % i == 0:
                k -= 1
                if k == 0:
                    return i
        return -1

class Solution1:
    def kthFactor(self, n: int, k: int) -> int:
        for i in range(1, n + 1):
            if n % i == 0:
                k -= 1
                if k == 0:
                    return i
        return -1
