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
// From huahua
class Solution {
 public:
  bool isPossible(vector<int>& target) {
    priority_queue<int> pq(target.begin(), target.end());
    long sum = accumulate(target.begin(), target.end(), 0L);
    while (true) {
      int t = pq.top(); pq.pop();
      sum -= t;
      if (t == 1 || sum == 1) return true;
      if (t < sum || sum == 0 || t % sum == 0) return false;
      t %= sum;
      sum += t;
      pq.push(t);
    }
    return true;
  }
};


class Solution_WA {
 public:
  bool isPossible(vector<int>& target) {
    const int n = target.size();
    sort(target.begin(), target.end());
    int sum = n, i = 0;
    while (i < n && target[i] == 1) ++i;
    if (i == n) return true;
    while (i < n) {
      if (target[i] < sum) {
        sum <<= 1;
        --sum;  // you may not change one to the new sum all the time.
      } else if (target[i] == sum) {
        ++i;
        sum <<= 1;
        --sum;
      } else {
        return false;
      }
    }
    return true;
  }
};

int main() {
  Solution s;
  
  return 0;
}
