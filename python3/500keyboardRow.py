class Solution:
    def findWords(self, words: List[str]) -> List[str]:
        row1 = 'qwertyuiop'
        row2 = 'asdfghjkl'
        row3 = 'zxcvbnm'
        res = []
        for Word in words:
            word = Word.lower()
            letter0 = word[0]
            i, stop = 1, len(word)
            if letter0 in row1:
                while i < stop:
                    if word[i] not in row1:
                        break
                    i+=1
                if i == stop:
                    res.append(Word)
            elif letter0 in row2:
                while i < stop:
                    if word[i] not in row2:
                        break
                    i+=1
                if i == stop:
                    res.append(Word)
            else:
                while i < stop:
                    if word[i] not in row3:
                        break
                    i+=1
                if i == stop:
                    res.append(Word)
        return res
