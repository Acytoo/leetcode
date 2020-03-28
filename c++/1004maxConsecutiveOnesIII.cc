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
#include <set>
#include <functional>
#include <bitset>
#include <numeric>
#include <deque>
#include <mutex>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
  // Sliding window
 public:
  int longestOnes(vector<int>& A, int K) {
    int slow = 0, res = 0, zeros = 0;
    for (int fast = 0, stop=A.size(); fast < stop; ++fast) {
      if (A[fast] == 0) ++zeros;
      while (zeros > K) {
        if (A[slow] == 0) --zeros;
        ++slow;
      }
      res = max(res, fast-slow+1);
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
