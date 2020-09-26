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
  vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
    vector<bool> in(n);
    for (const auto edge: edges) in[edge[1]] = true;
    vector<int> res;
    for (int i = 0; i < n; ++i)
      if (!in[i]) res.push_back(i);
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
