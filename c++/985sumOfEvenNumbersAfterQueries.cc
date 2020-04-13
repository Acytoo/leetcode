#include <iostream>
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
using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
    int sum = 0;
    for (const int a: A)
      if ((a & 1) == 0)
        sum += a;
    vector<int> res;
    for (const auto &q: queries) {
      int &a = A[q[1]];
      if ((a & 1) == 0)
        sum -= a;
      a += q[0];
      if ((a & 1) == 0)
        sum += a;
      res.push_back(sum);
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
