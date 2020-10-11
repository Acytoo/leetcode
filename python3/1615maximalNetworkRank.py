class Solution:
    def maximalNetworkRank(self, n: int, roads: List[List[int]]) -> int:
        cites = [0] * n
        g = [0] * (n * n)
        for r in roads:
            cites[r[0]] += 1
            cites[r[1]] += 1
            g[r[0] * n + r[1]] = g[r[1] * n + r[0]] = 1
        res, cur = 0, 0
        for i in range(n):
            for j in range(i + 1, n):
                cur = cites[i] + cites[j] - g[i * n + j]
                res = max(res, cur)
        return res
