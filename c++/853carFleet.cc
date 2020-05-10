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
  int carFleet(int target, vector<int>& position, vector<int>& speed) {
    const int n = speed.size();
    vector<pair<int, double>> cars;
    cars.reserve(n);
    for (int i = 0; i < n; ++i)
      cars.emplace_back(position[i], static_cast<double>(target - position[i]) / speed[i]);
    sort(cars.rbegin(), cars.rend());
    int res = 0;
    double max_time = .0;
    for (const auto &car: cars)
      if (max_time < car.second) {
        max_time = car.second;
        ++res;
      }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
