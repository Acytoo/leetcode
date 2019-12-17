from typing import List
import re
# Or tree

class Solution:
    def removeSubfolders(self, folder: List[str]) -> List[str]:
        # Sort the paths first, long paths can be sub folders of short paths
        map_paths = {}
        for x in folder:
            map_paths[x] = x.count('/')

        map_paths = sorted(map_paths.items(), key=lambda kv: kv[1])
        # paths = []
        # for i in map_paths:
            # paths.append(re.findall('[a-z]+', i[0]))
        # Path: name list of each folder, ascending
        init_len = map_paths[0][1]
        res= []
        i, n = 0, len(folder)

        while i < n and map_paths[i][1] == init_len:
            res.append(map_paths[i][0])
            i+=1
        while i < n:
            j, stop = 0, len(res)
            while j < stop:
                tmp_len = len(res[j])
                if map_paths[i][0][0:tmp_len] == res[j]:
                    break
                j += 1
            if j >= stop:
                res.append(map_paths[i][0])
            i += 1
        return res


if __name__ == '__main__':
    s = Solution()
    a = ['gaga', '///']
    a = ["/a","/a/b","/c/d","/c/d/e","/c/f"] #
    # a = ["/a","/a/b/c","/a/b/d"]
    # a = ["/a/b/c","/a/bsdgfdca","/a/b/d"]
    # a = ["/a/a","/a/ab"]
    # a = ["/a/b/c","/a/b/ca","/a/b/d"]
    res = s.removeSubfolders(a)
    print(res)
