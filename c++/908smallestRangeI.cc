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
  int smallestRangeI(vector<int>& A, int K) {
    int minn = A[0], maxx = A[0];
    for (const int a: A) {
      if (a < minn)
        minn = a;
      else if (maxx < a)
        maxx = a;
    }
    return max(0, maxx - minn - (K<<1));
  }
};

int main() {
  Solution s;
  
  return 0;
}
