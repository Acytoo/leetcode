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
  vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
    const int m = rolls.size();
    const int total = (m + n) * mean;
    const int left = total - accumulate(rolls.begin(), rolls.end(), 0);
    const double ave = static_cast<double>(left) / n;
    if (ave < 1 || ave > 6.0) return {};  // ave < 1
    const int ave_val = static_cast<int> (ave);
    vector<int> res (n, ave_val);
    int remainder = left - ave_val * n;
    for (int i = 0; i < remainder; ++i) ++res[i];
    return res;
  }
};

class Solution_WA1 {
 public:
  vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
    const int m = rolls.size();
    const int total = (m + n) * mean;
    const int left = total - accumulate(rolls.begin(), rolls.end(), 0);
    const double ave = static_cast<double>(left) / n;
    if (ave <= 0 || ave > 6.0) return {};
    const int ave_val = static_cast<int> (ave);
    vector<int> res (n, ave_val);
    int remainder = left - ave_val * n;
    for (int i = 0; i < remainder; ++i) ++res[i];
    return res;
  }
};

class Solution_WA {
 public:
  vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
    const int m = rolls.size();
    const int total = (m + n) * mean;
    const int left = total - accumulate(rolls.begin(), rolls.end(), 0);
    const double ave = static_cast<double>(left) / n;
    if (ave <= 0 || ave > 6.0) return {};
    vector<int> res;
    const int val = static_cast<int>(ave);
    for (int i = n - 1; i > 0; --i)
      res.emplace_back(val);
    res.emplace_back(left - val * (n - 1));
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
