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
// Greedy
class Solution {
 public:
  int scheduleCourse(vector<vector<int>>& courses) {
    sort(courses.begin(), courses.end(), [&] (const auto &a, const auto &b) {
      return a[1] < b[1];
    });
    int cur = 0;
    priority_queue<int> pq;
    for (const auto &c : courses) {
      cur += c[0];
      pq.push(c[0]);
      if (c[1] < cur) {
        cur -= pq.top();
        pq.pop();
      }
    }
    return pq.size();
  }
};

int main() {
  Solution s;
  
  return 0;
}
