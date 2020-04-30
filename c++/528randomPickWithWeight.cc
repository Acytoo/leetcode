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
#include <memory>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
// binary search
class Solution {
 public:
  Solution(vector<int>& w): sums_(move(w)) {
    srand(0);
    partial_sum(sums_.begin(), sums_.end(), sums_.begin());
  }

  int pickIndex() {
    int s = rand() % sums_.back();
    return upper_bound(sums_.begin(), sums_.end(), s) - sums_.begin();
  }
 private:
  vector<int> sums_;
};

int main() {
  Solution s;
  
  return 0;
}
