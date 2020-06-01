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
  vector<int> closestDivisors(int num) {
    auto divisors =
        [] (int num) -> vector<int> {
          for (int i = sqrt(num); i >= 1; --i)
            if (num % i == 0) return {i, num / i};  // i <= num / i
          return {-1, -1};
        };
    vector<int> res1 = divisors(num + 1),
                res2 = divisors(num + 2);
    return res1[1] - res1[0] < res2[1] - res2[0]? res1: res2;
  }
};

int main() {
  Solution s;
  
  return 0;
}
