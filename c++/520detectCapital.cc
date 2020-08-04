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
  bool detectCapitalUse(string word) {
    if (word[0] >= 'a') {  // all not cap
      for (const char c: word)
        if (c < 'a') return false;
      return true;
    } else {  // first cap
      if (word.size() == 1) return true;
      if (word[1] >= 'a') {  // only first cap
        for (int i = 1, stop = word.size(); i < stop; ++i)
          if (word[i] < 'a') return false;
        return true;
      } else {  // all cap
        for (const char c: word)
          if (c >= 'a') return false;
        return true;
      }
    }
    // return false;
  }
};

int main() {
  Solution s;
  
  return 0;
}
