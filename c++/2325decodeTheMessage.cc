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
class Solution {  // Slightly change of first method without much thinking
 public:
  string decodeMessage(string key, string message) {
    vector<char> dict('z' + 1, 0);
    char idx = 'a' - 1;
    for (const char c : key)
      if (c != ' ' && dict[c] == 0) dict[c] = ++idx;
    for (char &c : message)
      if (c != ' ') c = dict[c];
    return message;
  }
};

class Solution1 {  // First thought without thinking
 public:
  string decodeMessage(string key, string message) {
    bitset<'z' + 1> s;
    vector<char> dict('z' + 1);
    int idx = static_cast<int>('a');
    for (const char c : key) {
      if (c == ' ' || s[c]) continue;
      s[c] = 1;
      dict[c] = idx;
      ++idx;
    }
    for (char &c : message)
      if (c != ' ')
        c = dict[c];
    return message;
  }
};

int main() {
  Solution s;
  
  return 0;
}
