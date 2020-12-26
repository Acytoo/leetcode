from typing import List

# from huahua
class Solution:
    def minCost(self, s: str, cost: List[int]) -> int:
        s = "*" + s + "*"
        cost = [0] + cost + [0]
        res, t, m, n = 0, 0, 0, len(s)
        for i in range(1, n):
            if s[i] != s[i - 1]:
                res += t - m
                t = m = 0
            t += cost[i]
            m = max(m, cost[i])
        return res