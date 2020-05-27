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
  int numPrimeArrangements(int n) {
    if (n <= 2) return 1;

    constexpr int kMod = 1e9 + 7;
    int prime_num = 1;
    auto isPrime = [] (int num) {  // num >= 3
                     for (int i = 2, stop = sqrt(num); i <= stop; ++i)
                       if (num % i == 0)
                         return false;
                     return true;
                   };
    for (int i = 3; i <= n; ++i)
      prime_num += isPrime(i);
    long res = 1;
    for (int i = 2; i <= prime_num; ++i)
      res = (res * i) % kMod;
    for (int i = n - prime_num; i > 1; --i)
      res = (res * i) % kMod;
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
