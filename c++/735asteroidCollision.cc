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

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  vector<int> asteroidCollision(vector<int>& asteroids) {
    deque<int> dq;
    vector<int> res;
    for (const int i: asteroids)
      if (i > 0) {
        dq.push_back(i);
      } else {
        int ii = -i;
        while (!dq.empty() && dq.back() < ii)  dq.pop_back();
        if (!dq.empty() && dq.back() == ii)
          dq.pop_back();
        else if (dq.empty())
          res.push_back(i);
      }

    while (!dq.empty()) {
      res.push_back(dq.front());
      dq.pop_front();
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
