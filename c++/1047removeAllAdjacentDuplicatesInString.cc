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
  string removeDuplicates(string s) {
    deque<char> dq;
    for (const char c : s) {
      if (!dq.empty() && c == dq.back())
        dq.pop_back();
      else
        dq.push_back(c);
    }
    string res;
    while (!dq.empty()) {
      res += dq.front();
      dq.pop_front();
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
