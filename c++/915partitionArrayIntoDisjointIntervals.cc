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
  int partitionDisjoint(vector<int>& A) {
    int left_max = A.front(), cur_max = left_max, res_idx = 0;
    for (int i = 1, stop = A.size(); i < stop; ++i) {
      if (A[i] < left_max) {
        res_idx = i;
        left_max = cur_max;
      } else {
        if (cur_max < A[i]) cur_max = A[i];
      }
    }
    return res_idx + 1;
  }
};

int main() {
  Solution s;

  return 0;
}
