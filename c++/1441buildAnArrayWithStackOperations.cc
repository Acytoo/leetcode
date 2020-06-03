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
  vector<string> buildArray(vector<int>& target, int n) {
    vector<string> res;
    for (int i = 0, stop = target.size(), num = 1; i < stop; ++num)
      if (target[i] == num) {
        res.emplace_back("Push");
        ++i;
      } else {
        res.emplace_back("Push");
        res.emplace_back("Pop");
      }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
