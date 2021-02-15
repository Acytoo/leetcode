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
  int maximumScore(int a, int b, int c) {
    vector<int> tmp {a, b, c};
    sort(tmp.begin(), tmp.end());
    const int two_sum = tmp[0] + tmp[1];
    if (two_sum <= tmp[2])
      return two_sum;
    return (two_sum + tmp[2]) >> 1;
  }
};

int main() {
  Solution s;
  
  return 0;
}
