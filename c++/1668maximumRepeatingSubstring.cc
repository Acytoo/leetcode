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
  int maxRepeating(string sequence, string word) {
    if (word.size() >= sequence.size()) return sequence == word;
    string s (word);
    for (int res = 0;; ++res) {
      if (sequence.find(s) == string::npos) return res;
      s += word;
    }
    return 0;
  }
};

int main() {
  Solution s;

  return 0;
}
