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
class Solution_NEW {
 public:
  int minSetSize(vector<int>& arr) {
    unordered_map<int, int> m;
    for (const int a : arr) ++m[a];
    vector<int> occs;
    for (auto it : m) occs.emplace_back(it.second);
    sort(occs.rbegin(), occs.rend());
    int res = 0, del = 0;
    const int target = arr.size() / 2;
    while (del < target) del += occs[++res];
    return res;
  }
};

class Solution {
 public:
  int minSetSize(vector<int>& arr) {
    unordered_map<int, int> m;
    for (const int a : arr) ++m[a];
    vector<int> occs;
    occs.reserve(m.size());
    for (const auto &[k, v] : m) occs.emplace_back(v);
    sort(occs.rbegin(), occs.rend());
    int res = 0, cur = 0;
    for (int i = 0, n = occs.size(), cur = 0, half = arr.size() >> 1; cur < half && i < n; ++i) {
      ++res;
      cur += occs[i];
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
