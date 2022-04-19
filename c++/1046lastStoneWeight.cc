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
#include <set>
#include <functional>
using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int lastStoneWeight(vector<int>& stones) {
    priority_queue<int> pq(stones.begin(), stones.end());
    while (pq.size() > 2) {
      const int one = pq.top(); pq.pop();
      const int two = pq.top(); pq.pop();
      if (one != two) pq.push(one - two);
    }
    if (pq.size() == 1) return pq.top();
    const int one = pq.top(); pq.pop();
    const int two = pq.top(); pq.pop();
    return one - two;
  }
};

class Solution_OLD {
 public:
  int lastStoneWeight(vector<int>& stones) {
    // priority_queue
    priority_queue<int> queue(stones.begin(), stones.end());
    while (1 < queue.size()) {
      int a = queue.top();
      queue.pop();
      int b = queue.top();
      queue.pop();
      if (a != b)
        queue.push(a-b);
    }
    // queue.size() == 1 || == 0
    return queue.empty()? 0: queue.top();
  }
};

int main() {
  Solution s;
  
  return 0;
}
