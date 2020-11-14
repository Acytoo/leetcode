class Solution:
    def trimMean(self, arr: List[int]) -> float:
      n = len(arr)
      r = int(n / 20)
      s = 0
      list.sort(arr)
      for i in range(r, n - r):
        s += arr[i]
      return s / (n - r * 2)


# more "python" code from leetcode
class Solution:
    def trimMean(self, arr: List[int]) -> float:
        l = len(arr)
        toremove = ((l * 5) // 100)
        remaining = sorted(arr)[toremove:l-toremove]
        s = 0
        for n in remaining:
            s += n
        return s / (l-toremove*2)
