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

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  bool canConstruct(string ransomNote, string magazine) {
    if (ransomNote.empty()) return true;
    if (magazine.size() < ransomNote.size()) return false;

    vector<int> dict ('z'+1);
    for (const char c: magazine) ++dict[c];
    for (const char c: ransomNote)
      if (--dict[c] < 0) return false;
    return true;
  }
};

int main() {
  Solution s;
  
  return 0;
}
