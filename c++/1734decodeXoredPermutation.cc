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
  vector<int> decode(vector<int>& encoded) {
    const int n = encoded.size() + 1;
    int first = 0;
    for (int i = 0; i <= n; ++i) first ^= i;
    for (int i = 1; i < n; i += 2) first ^= encoded[i];
    vector<int> res {first};
    for_each(encoded.begin(), encoded.end(),
             [&] (const int a) { res.emplace_back(res.back() ^ a); });
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
