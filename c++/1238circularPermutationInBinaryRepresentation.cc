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
  vector<int> circularPermutation(int n, int start) {
    n = 1 << n;
    vector<int> res (n);
    for (int i = 0; i < n; ++i)
      res[i] = start ^ i ^ i >> 1;
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
