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
  int minDeletions(string s) {
    int chars['z' + 1];
    memset(chars, 0, sizeof(chars));
    for (const char c: s) ++chars[c];
    unordered_set<int> freq;
    int res = 0;
    for (int i = 'a'; i <= 'z'; ++i) {
      while (freq.count(chars[i]) && chars[i] > 0) {
        --chars[i];
        ++res;
      }
      if (chars[i] != 0) freq.insert(chars[i]);
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
