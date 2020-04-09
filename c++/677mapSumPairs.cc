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
#include <functional>
#include <bitset>
#include <numeric>
#include <deque>
#include <mutex>
#include <utility>
using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class MapSum {
 public:
  /** Initialize your data structure here. */
  MapSum() {
    m_.clear();
  }

  void insert(string key, int val) {
    m_[key] = val;
  }

  int sum(string prefix) {
    int res = 0;
    const int kLen = prefix.size();
    for (auto it: m_)
      if (it.first.substr(0, kLen) == prefix)
        res += it.second;
    return res;
  }
 private:
  unordered_map<string, int> m_;
};

int main() {
  Solution s;
  
  return 0;
}
