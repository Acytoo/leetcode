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
  vector<int> beautifulArray(int N) {
    if (N == 1) return {1};
    vector<int> even, odd, res;
    even = beautifulArray(N >> 1);
    odd = beautifulArray(N - (N >> 1));
    res.reserve(N);
    for (const int num: odd) res.emplace_back((num << 1) - 1);
    for (const int num: even) res.emplace_back(num << 1);
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
