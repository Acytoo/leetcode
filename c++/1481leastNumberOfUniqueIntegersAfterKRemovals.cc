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
  int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
    if (arr.size() == k) return 0;
    unordered_map<int, int> m;
    for (const int a: arr) ++m[a];
    vector<int> occs;
    occs.reserve(m.size());
    for (const auto &[_, occ]: m)
      occs.emplace_back(occ);
    sort(occs.begin(), occs.end());
    int i = 0;
    while (k >= occs[i])
      k -= occs[i++];
    return occs.size() - i;
  }
};

int main() {
  Solution s;
  
  return 0;
}
