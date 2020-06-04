#include <iostream>
#include <sstream>
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
#include <functional>
#include <bitset>
#include <numeric>
#include <deque>
#include <mutex>
#include <utility>
#include <memory>
#include <cstring>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int isPrefixOfWord(string sentence, string searchWord) {
    int idx = 1, i = 0, j = 0, m = searchWord.size(), n = sentence.size();
    while (j < n) {
      if (i == m) return idx;
      if (sentence[j] == ' ') {
        ++idx;
        i = 0;
        ++j;
        continue;
      }
      if (sentence[j] == searchWord[i]) {
        ++i;
        ++j;
      } else {
        i = 0;
        while (j < n && sentence[j] != ' ') ++j;
      }
    }
    return i == m? idx: -1;
  }
};

int main() {
  Solution s;
  
  return 0;
}
