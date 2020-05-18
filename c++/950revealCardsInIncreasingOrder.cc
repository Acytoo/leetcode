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
  vector<int> deckRevealedIncreasing(vector<int>& deck) {
    const int n = deck.size();
    sort(deck.rbegin(), deck.rend());
    deque<int> dq;
    dq.push_back(deck[0]);
    int i = 0;
    while (++i < n) {
      if (!dq.empty()) {
        dq.push_back(dq.front());
        dq.pop_front();
      }
      dq.push_back(deck[i]);
    }
    vector<int> res;
    res.reserve(n);
    while (!dq.empty()) {
      res.push_back(dq.back());
      dq.pop_back();
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
