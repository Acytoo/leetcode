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
// 1 <= word.length <= 250
// word consists of lowercase English letters.
// ch is a lowercase English letter.
class Solution {
 public:
  string reversePrefix(string word, char ch) {
    int l = 0, r = word.find(ch);  // word.length <= 250, int / size_t
    if (r == string::npos) return word;
    while (l < r) {
      swap(word[l], word[r]);
      ++l; --r;
    }
    return word;
  }
};

int main() {
  Solution s;
  
  return 0;
}
