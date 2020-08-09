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
  string makeGood(string s) {
    deque<char> dq;
    dq.push_back(s.front());
    for (int i = 1, stop = s.size(); i < stop; ++i)
      if (!dq.empty() && (dq.back() ^ s[i]) == 32)
        dq.pop_back();
      else
        dq.push_back(s[i]);
    string res;
    while (!dq.empty()) {
      res.push_back(dq.front());
      dq.pop_front();
    }
    return res;
  }
};

int main() {
  Solution s;
  string a = "Ll";
  cout << s.makeGood(a) << endl;
  return 0;
}
