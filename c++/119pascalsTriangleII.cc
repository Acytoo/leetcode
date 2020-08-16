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
  vector<int> getRow(int rowIndex) {
    vector<int> res (rowIndex + 1);
    res[0] = 1;
    for (int i = 1; i <= rowIndex; ++i)
      for (int j = i; j >= 1; --j)
        res[j] += res[j - 1];
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
