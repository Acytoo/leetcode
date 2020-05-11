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
  vector<int> advantageCount(vector<int>& A, vector<int>& B) {
    vector<int> res;
    res.reserve(A.size());
    multiset<int> s (A.begin(), A.end());

    for (const int b: B) {
      auto it = s.upper_bound(b);
      if (it == s.end()) it = s.begin();
      res.push_back(*it);
      s.erase(it);
    }

    return res;
  }
};
// upper_bound(s.begin(), s.end(), b) vs s.upper_bound(b)
class Solution_TLE {
 public:
  vector<int> advantageCount(vector<int>& A, vector<int>& B) {
    vector<int> res;
    res.reserve(A.size());
    multiset<int> s (A.begin(), A.end());

    for (const int b: B) {
      auto it = upper_bound(s.begin(), s.end(), b);
      if (it == s.end()) it = s.begin();
      res.push_back(*it);
      s.erase(it);
    }

    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
