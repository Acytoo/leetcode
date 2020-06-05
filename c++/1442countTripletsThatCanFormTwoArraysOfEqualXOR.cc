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
  int countTriplets(vector<int>& arr) {
    int res = 0;
    for (int i = 0, stop = arr.size(); i < stop; ++i) {
      int num = 0;
      for (int j = i; j < stop; ++j) {
        num ^= arr[j];
        if (num == 0 && (j - i) > 0) res += (j - i);
      }
    }
    return res;
  }
};

class Solution_same {
 public:
  int countTriplets(vector<int>& arr) {
    int res = 0;
    for (int i = 0, stop = arr.size(), num = 0; i < stop; ++i, num = 0)
      for (int j = i; j < stop; ++j)
        if (!(num ^= arr[j])) res += j - i;  // if j == i, then j - i == 0
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
