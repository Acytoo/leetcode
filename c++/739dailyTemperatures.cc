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
// DP
class Solution {
 public:
  vector<int> dailyTemperatures(vector<int>& T) {
    int n = T.size();
    vector<int> res (n, 0);
    function<int(int, int)> findDay = [&] (int i, int j) -> int {
                                        if (j >= n)
                                          return 0;
                                        if (T[j] > T[i])
                                          return j-i;
                                        if (res[j] == 0)
                                          return 0;
                                        return findDay(i, j+res[j]);
                                      };
    for (int i=n-2; i>=0; --i)
      res[i] = findDay(i, i+1);
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
