class Solution:
    def constructRectangle(self, area: int) -> List[int]:
        x = int(math.ceil(area ** 0.5))
        while area % x != 0:
            x += 1
        return [x, int(area/x)]
