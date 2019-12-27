class Solution:
    def judgeCircle(self, moves: str) -> bool:
        dic = {'R': 0, 'L': 0, 'U': 0, 'D': 0}
        for i in moves:
            dic[i] += 1
        return dic['R'] == dic['L'] and dic['U'] == dic['D']
