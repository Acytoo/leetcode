class Solution:
    def factorial(self, n):
        if n < 2:
            return 1
        i = 1
        res = 1
        while i <= n:
            res *= i
            i += 1
        return res

    def getRow(self, rowIndex):
        """
        :type rowIndex: int
        :rtype: List[int]
        """
        if rowIndex < 1:
            return [1]
        facn = self.factorial(rowIndex)
        i = 0
        res = []
        while i <= rowIndex:
            res.append(
                int(facn/(self.factorial(i)*self.factorial(rowIndex - i))))
            i += 1

        return res


if __name__ == '__main__':
    s = Solution()
    print(s.getRow(13))
