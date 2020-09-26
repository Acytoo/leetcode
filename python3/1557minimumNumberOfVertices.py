class Solution:
    def findSmallestSetOfVertices(self, n: int, edges: List[List[int]]) -> List[int]:
      innode = [False] * n
      for edge in edges:
        innode[edge[1]] = True
      res = []
      for i in range(n):
        if not innode[i]:
          res.append(i)
      return res