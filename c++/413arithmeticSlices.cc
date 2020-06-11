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
  int numberOfArithmeticSlices(vector<int>& A) {
    int res = 0, cur = 0;
    for (int i = 2, stop = A.size(); i < stop; ++i)
      if (A[i - 2] - A[i - 1] == A[i - 1] - A[i])
        res += ++cur;
      else
        cur = 0;
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
