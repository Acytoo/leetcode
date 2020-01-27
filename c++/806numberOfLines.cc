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
  vector<int> numberOfLines(vector<int>& widths, string S) {
    int curW = 0, lines = 1;
    for (char c: S) {
      if (curW + widths[c-'a'] <= 100) {
        curW += widths[c-'a'];
      } else {
        ++lines;
        curW = widths[c-'a'];
      }
    }
    return vector<int> {lines, curW};
  }
};

int main() {
  Solution s;
  
  return 0;
}
