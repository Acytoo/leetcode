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
  vector<int> frequencySort(vector<int>& nums) {
    int num_occ[201];
    memset(num_occ, 0, sizeof(num_occ));
    for (const int a: nums) ++num_occ[a + 100];

    vector<pair<int, int>> occ_num;
    occ_num.reserve(100);
    for (int i = 0; i < 201; ++i)
      if (num_occ[i])
        occ_num.emplace_back(num_occ[i], i - 100);

    sort(occ_num.begin(), occ_num.end(), [&] (const pair<int, int> &a, pair<int, int>& b) {
      if (a.first != b.first) return a.first < b.first;
      return a.second > b.second;
    });

    vector<int> res;
    res.reserve(nums.size());
    for (auto &[occ, num]: occ_num)
      while (occ-- > 0)
        res.emplace_back(num);
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
