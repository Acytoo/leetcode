#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <climits>
#include <stack>
#include <algorithm>
#include <cmath>
#include <set>
#include <unordered_map>
#include <list>
#include <unordered_set>
#include <map>
#include <set>
#include <functional>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();

class Solution {
 public:
  int videoStitching(vector<vector<int>>& clips, int T) {
    sort(clips.begin(), clips.end());
    int res = 0;
    int i = 0, last = 0, cur = 0, n = clips.size()-1;
    while (cur < T) {
      while(i <= n && clips[i][0] <= last)
        cur = max(cur, clips[i++][1]);
      if (last == cur)
        return -1;
      last = cur;
      ++res;
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
